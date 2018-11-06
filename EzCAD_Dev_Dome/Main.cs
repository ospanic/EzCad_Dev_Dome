using System;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.IO.Ports;
using System.Management;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows.Forms;

namespace EzCAD_Dev_Dome
{
    public partial class Main_Form : Form
    {
        public Main_Form()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;
        }

        string ezdFileName = ""; //用来存储模板文件的文件路径

        [DllImport(@"MarkEzd.dll", EntryPoint = "lmc1_Close", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern Int32 lmc1_Close();

        [DllImport("MarkEzd.dll", EntryPoint = "lmc1_Initial", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern int lmc1_Initial(string strEzCadPath, int bTestMode, IntPtr hOwenWnd);

        [DllImport("MarkEzd.dll", EntryPoint = "lmc1_LoadEzdFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern int lmc1_LoadEzdFile(string strFileName);

        [DllImport("MarkEzd.dll", EntryPoint = "lmc1_ChangeTextByName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern int lmc1_ChangeTextByName(string strTextName, string strTextNew);

        [DllImport("MarkEzd.dll", EntryPoint = "lmc1_DeleteEnt", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern int lmc1_DeleteEnt(string strEntName);

        [DllImport("MarkEzd.dll", EntryPoint = "lmc1_Mark", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern int lmc1_Mark(int bFlyMark);

        [DllImport("MarkEzd.dll", EntryPoint = "lmc1_RedLightMark", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        public static extern Int32 lmc1_RedLightMark(); //显示一次红光对标

        [DllImport("MyMarkEzd.dll", EntryPoint = "CsGetHBitmap", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CsGetHBitmap(IntPtr hOwenWnd, int width, int height);

        [DllImport("MyMarkEzd_xp.dll", EntryPoint = "CsGetHBitmap", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CsGetHBitmap_XP(IntPtr hOwenWnd, int width, int height);

        private void Form_Load(object sender, EventArgs e)
        {
            int c = lmc1_Initial(Application.StartupPath, 0, Handle);  //初始化激光雕刻机

            if (c != 0)
            {
                MessageBox.Show("初始化Lmc失败\r\n错误代码：" + c + "\r\n错误原因:" + EzCad_Error_Code.ErrorMessage[c]);
                //lmc1_Close();
            }
            ezdFileName = Application.StartupPath + "/test.ezd";
            fileNametBox.Text = "test.ezd";
        }

        void debug_string(string s)
        {
            //log_tBox.AppendText(s);
            //log_tBox.CreateControl();
        }   

        private void openFilebtn_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.InitialDirectory = Application.StartupPath;
            dialog.Multiselect = false;//多个文件
            dialog.Title = "请选择丝印文件";
            dialog.Filter = "Ezd文件(*.Ezd)|*.ezd";
            if (dialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                ezdFileName = dialog.FileName;
                fileNametBox.Text = dialog.SafeFileName;
                fileNametBox.BackColor = Color.LightGreen;
            }
        }
        private void preview_btn_Click(object sender, EventArgs e)
        {
            if (!File.Exists(ezdFileName))
            {
                fileNametBox.BackColor = Color.Red;
                MessageBox.Show("请先选择丝印文件!!!\r\n");
                return;
            }

            int c = 5;

            while (c-- > 0)
            {
                if (lmc1_LoadEzdFile(ezdFileName) == 0)         //加载模板丝印文件
                    break;
                lmc1_Close();
                Thread.Sleep(200);
                lmc1_Initial(Application.StartupPath, 0, Handle);
                Thread.Sleep(100);
            }

            if (c < 0)
            {
                lmc1_Close();
                MessageBox.Show("加载丝印文件出错，请重试！！！");
                return;
            }

            lmc1_ChangeTextByName("test_qr", textBox.Text); //修改二维码
            lmc1_ChangeTextByName("test_str", textBox.Text); //修改文本

            Bitmap m = null;
            try
            {
                if (Environment.OSVersion.Version.Major > 5) //主版本号大于五为Vasta以上系统
                {
                    m = Image.FromHbitmap(CsGetHBitmap(Handle, 560, 320)); //获取预览图片，win7及以上
                }
                else
                {
                    m = Image.FromHbitmap(CsGetHBitmap_XP(Handle, 560, 320));//获取预览图片，XP系统
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("获取预览图时发生错误：" + ex.Message);
                return;
            }

            if (m == null)
            {
                MessageBox.Show("无法获取预览图！！！");
                lmc1_Close();
                return;
            }
            else
            {
                pictureBox.Image = m;
            }
        }

        private void redline_btn_Click(object sender, EventArgs e)
        {
            lmc1_RedLightMark();
            Thread.Sleep(10);
            lmc1_RedLightMark();
            Thread.Sleep(10);
            lmc1_RedLightMark();
            Thread.Sleep(10);
            lmc1_RedLightMark();
            Thread.Sleep(10);
        }

        private void mark_btn_Click(object sender, EventArgs e)
        {
            int c = lmc1_Mark(0); //执行镭雕

            if (c == 0)
            {
            }
            else
            {
                MessageBox.Show("雕刻时出错\r\n错误代码：" + c + "\r\n错误原因:" + EzCad_Error_Code.ErrorMessage[c]);
            }
        }

        private void cancel_btn_Click(object sender, EventArgs e)
        {
            
        }

        private void ScinanLaserForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            lmc1_Close();
        }


    }
}
