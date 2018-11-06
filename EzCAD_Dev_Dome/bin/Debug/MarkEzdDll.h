	#ifndef MARKEZDDLL_H
#define MARKEZDDLL_H

//所有函数都返回一个整形值
#define LMC1_ERR_SUCCESS         0  //成功
#define LMC1_ERR_EZCADRUN        1  //发现EZCAD在运行
#define LMC1_ERR_NOFINDCFGFILE   2  //找不到EZCAD.CFG
#define LMC1_ERR_FAILEDOPEN      3  //打开LMC1失败
#define LMC1_ERR_NODEVICE        4  //没有有效的lmc1设备
#define LMC1_ERR_HARDVER         5  //lmc1版本错误
#define LMC1_ERR_DEVCFG          6  //找不到设备配置文件
#define LMC1_ERR_STOPSIGNAL      7  //报警信号
#define LMC1_ERR_USERSTOP        8  //用户停止
#define LMC1_ERR_UNKNOW          9  //不明错误
#define LMC1_ERR_OUTTIME         10 //超时
#define LMC1_ERR_NOINITIAL       11 //未初始化
#define LMC1_ERR_READFILE        12 //读文件错误
#define LMC1_ERR_OWENWNDNULL     13 //窗口为空
#define LMC1_ERR_NOFINDFONT      14 //找不到指定名称的字体
#define LMC1_ERR_PENNO           15 //错误的笔号
#define LMC1_ERR_NOTTEXT         16 //指定名称的对象不是文本对象
#define LMC1_ERR_SAVEFILE        17 //保存文件失败
#define LMC1_ERR_NOFINDENT           18 //找不到指定对象
#define LMC1_ERR_STATUE        19 //当前状态下不能执行此操作

//初始化lmc1控制卡
//输入参数: strEzCadPath  EzCad软件的执行路径
//          bTestMode = TRUE 表示测试模式  bTestMode = FALSE 表示正常模式
//          pOwenWnd      表示父窗口对象，如果需要实现停止打标，则系统会从此窗口截取消息 
typedef int (*LMC1_INITIAL)(TCHAR* strEzCadPath,//ezcad的工作目录
							BOOL bTestMode,//是否是测试模式
							HWND hOwenWnd);//父窗口

//关闭lmc1控制卡
typedef int (*LMC1_CLOSE)();

//载入ezd文件，并清除数据库所有对象
//输入参数: strFileName  EzCad文件名称
typedef int (*LMC1_LOADEZDFILE)(TCHAR* strFileName);

//标刻当前数据库里的所有数据
//输入参数: bFlyMark = TRUE 使能飞动打标  bFlyMark = FALSE 使能飞动打标
typedef int (*LMC1_MARK)(BOOL bFlyMark);

//标刻当前数据库里的指定对象
//输入参数: strEntName 要加工的指定对象的名称
typedef int (*LMC1_MARKENTITY)(TCHAR* strEntName);

//飞动标刻当前数据库里的指定对象
//输入参数: strEntName 飞动打标指定对象的名称
typedef int (*LMC1_MARKENTITYFLY)(TCHAR* strEntName);

// 读lmc1的输入端口
//输入参数: 读入的输入端口的数据
typedef int (*LMC1_READPORT)(WORD& data);

// 写lmc1的输出端口
//输入参数: 要写到的输出端口的数据
typedef int (*LMC1_WRITEPORT)(WORD data);

//得到当前数据库里的所有数据的预览图像
//输入参数: pWnd         预览图像显示到哪个窗口
//          nBMPWIDTH    预览图像的宽度
//          nBMPHEIGHT   预览图像的高度
typedef  CBitmap* (*LMC1_GETPREVBITMAP)(HWND hwnd,int nBMPWIDTH,int nBMPHEIGHT);

//得到当前数据库里的指定对象数据的预览图像
//输入参数: pWnd         预览图像显示到哪个窗口
//          nBMPWIDTH    预览图像的宽度
//          nBMPHEIGHT   预览图像的高度
//          strEntName    指定对象的名称
typedef  CBitmap* (*LMC1_GETPREVBITMAPBYNAME)(TCHAR* strEntName,HWND hwnd,int nBMPWIDTH,int nBMPHEIGHT);

//调用设置设备参数的对话框
typedef int (*LMC1_SETDEVCFG)();

const int HATCHATTRIB_ALLCALC = 0x01;//全部对象作为整体一起计算
const int HATCHATTRIB_BIDIR   = 0x08;//双向填充
const int HATCHATTRIB_EDGE    = 0x02;//走一次边
const int HATCHATTRIB_LOOP    = 0x10;//环形填充

//设置当前的填充参数，如果要向数据库里添加新对象时使能填充时，会使用此参数填充
typedef int (*LMC1_SETHATCHPARAM)(BOOL   bEnableContour,//使能轮廓本身
					  int    bEnableHatch1,//使能填充1
					  int    nPenNo1,//填充笔	
					  int    nHatchAttrib1,//填充属性
					  double dHatchEdgeDist1,//填充线边距
					  double dHatchLineDist1,//填充线间距
					  double dHatchStartOffset1,//填充线起始偏移距离
					  double dHatchEndOffset1,//填充线结束偏移距离
					  double dHatchAngle1,//填充线角度	(弧度值)
					  int    bEnableHatch2,//使能填充1
					  int    nPenNo2,//填充笔	
					  int    nHatchAttrib2,//填充属性
					  double dHatchEdgeDist2,//填充线边距
					  double dHatchLineDist2,//填充线间距
					  double dHatchStartOffset2,//填充线起始偏移距离
					  double dHatchEndOffset2,//填充线结束偏移距离
					  double dHatchAngle2);//填充线角度	(弧度值)	

//设置当前的字体参数，如果要向数据库里添加新文本对象时会使用此字体参数
typedef int (*LMC1_SETFONTPARAM)(TCHAR* strFontName,//字体名称
					 double dCharHeight,//字符高度
					 double dCharWidth,//字符宽度
					 double dCharAngle,//字符倾角
					 double dCharSpace,//字符间距
					 double dLineSpace,//行间距
					 BOOL   bEqualCharWidth);//等字符宽度模式

//得到指定笔号对应的加工参数
typedef int (*LMC1_GETPENPARAM)(int      nPenNo,//要设置的笔号(0-255)					 
					 int&      nMarkLoop,//加工次数
					 double&   dMarkSpeed,//标刻次数mm/s
					 double&   dPowerRatio,//功率百分比(0-100%)	
					 double&   dCurrent,//电流A
					 int&      nFreq,//频率HZ
					 //int&      nQPulseWidth,//Q脉冲宽度us	
					 double&      dQPulseWidth,//Q脉冲宽度us	
					 int&      nStartTC,//开始延时us
					 int&      nLaserOffTC,//激光关闭延时us 
					 int&      nEndTC,//结束延时us
					 int&      nPolyTC,//拐角延时us   //	
					 double&   dJumpSpeed, //跳转速度mm/s
					 int&      nJumpPosTC, //跳转位置延时us
					 int&      nJumpDistTC,//跳转距离延时us	
					 double&   dEndComp,//末点补偿mm
					 double&   dAccDist,//加速距离mm	
					 double&   dPointTime,//打点延时 ms						 
					 BOOL&     bPulsePointMode,//脉冲点模式 
					 int&      nPulseNum,//脉冲点数目
					 double&   dFlySpeed);


typedef int (*LMC1_GETPENPARAM2)(int       nPenNo,//要设置的笔号(0-255)						 
					  int&      nMarkLoop,//加工次数
					  double&   dMarkSpeed,//标刻次数mm/s
					  double&   dPowerRatio,//功率百分比(0-100%)	
					  double&   dCurrent,//电流A
					  int&      nFreq,//频率HZ
					  double&      dQPulseWidth,//Q脉冲宽度us	
					  int&      nStartTC,//开始延时us
					  int&      nLaserOffTC,//激光关闭延时us 
					  int&      nEndTC,//结束延时us
					  int&      nPolyTC,//拐角延时us   //	
					  double&   dJumpSpeed, //跳转速度mm/s
					  int&      nJumpPosTC, //跳转位置延时us
					  int&      nJumpDistTC,//跳转距离延时us	
					  double&   dPointTime,//打点延时 ms		
					  int& nSpiWave,
					  BOOL&     bWobbleMode,
					  double&   bWobbleDiameter,
					  double&   bWobbleDist);

//设置指定笔号对应的加工参数
typedef int (*LMC1_SETPENPARAM)(int      nPenNo,//要设置的笔号(0-255)					 
					 int      nMarkLoop,//加工次数
					 double   dMarkSpeed,//标刻次数mm/s
					 double   dPowerRatio,//功率百分比(0-100%)	
					 double   dCurrent,//电流A
					 int      nFreq,//频率HZ
					 //int      nQPulseWidth,//Q脉冲宽度us	
					 double      dQPulseWidth,//Q脉冲宽度us
					 int      nStartTC,//开始延时us
					 int      nLaserOffTC,//激光关闭延时us 
					 int      nEndTC,//结束延时us
					 int      nPolyTC,//拐角延时us   //	
					 double   dJumpSpeed, //跳转速度mm/s
					 int      nJumpPosTC, //跳转位置延时us
					 int      nJumpDistTC,//跳转距离延时us	
					 double   dEndComp,//末点补偿mm
					 double   dAccDist,//加速距离mm	
					 double   dPointTime,//打点延时 ms						 
					 BOOL     bPulsePointMode,//脉冲点模式 
					 int      nPulseNum,
					 double   dFlySpeed);//脉冲点数目


//设置指定笔号对应的加工参数
typedef int (*LMC1_SETPENPARAM2)(int      nPenNo,//要设置的笔号(0-255)					 
					  int      nMarkLoop,//加工次数
					  double   dMarkSpeed,//标刻次数mm/s
					  double   dPowerRatio,//功率百分比(0-100%)	
					  double   dCurrent,//电流A
					  int      nFreq,//频率HZ
					  double      dQPulseWidth,//Q脉冲宽度us	
					  int      nStartTC,//开始延时us
					  int      nLaserOffTC,//激光关闭延时us 
					  int      nEndTC,//结束延时us
					  int      nPolyTC,//拐角延时us   //	
					  double   dJumpSpeed, //跳转速度mm/s
					  int      nJumpPosTC, //跳转位置延时us
					  int      nJumpDistTC,//跳转距离延时us	
					  int nSpiWave,
					  BOOL     bWobbleMode,
					  double   bWobbleDiameter,
					  double   bWobbleDist);
//清除对象库里所有数据
typedef int (*LMC1_CLEARENTLIB)();  

//对齐方式时数字代表的意义
//   6 ---  5 --- 4
//   |            |
//   |            |
//   7     8      3
//   |            |
//   |            |
//   0 ---  1 --- 2
//加入新文本到数据库中
typedef int (*LMC1_ADDTEXTTOLIB)(TCHAR* pStr,//要添加的字符串
								  TCHAR* pEntName,//字符串对象名称
					  double dPosX,//字符串的左下角基点的x坐标
					  double dPosY,//字符串的左下角基点的y坐标
					  double dPosZ,//字符串对象的z坐标
					  int    nAlign,//对齐方式0－8
					  double dTextRotateAngle,//字符串绕基点旋转的角度值(弧度值)
					  int nPenNo,//对象使用的加工参数
					  BOOL bHatchText);//是否填充文本对象
//加入指定文件到数据库中
//支持的文件有ezd,dxf,dst,plt,ai,bmp,jpg,tga,png,gif,tiff等
typedef int  (*LMC1_ADDFILETOLIB)(TCHAR* pFileName,	//文件名称
								   TCHAR* pEntName,//字符串对象名称
					  double dPosX, //文件左下角基点x坐标
					  double dPosY, //文件左下角基点y坐标
					  double dPosZ, //文件z坐标
					  int    nAlign,//对齐方式0－8
					  double dRatio,//文件缩放比例				  
					  int nPenNo,//对象使用的加工参数
					  BOOL bHatchFile);//是否填充文件对象 如果是ezd文件或位图文件此参数无效


//加入曲线到数据库中
typedef int (*LMC1_ADDCURVETOLIB)(double ptBuf[][2],//曲线顶点数组
					   int  ptNum,//曲线顶点数
					   TCHAR* pEntName,//曲线对象名称
					   int nPenNo,//曲线对象使用的笔号
					   int bHatch);//曲线是否填充


#define BARCODETYPE_39      0
#define BARCODETYPE_93      1
#define BARCODETYPE_128A    2
#define BARCODETYPE_128B    3
#define BARCODETYPE_128C    4
#define BARCODETYPE_128OPT  5
#define BARCODETYPE_EAN128A 6
#define BARCODETYPE_EAN128B 7
#define BARCODETYPE_EAN128C 8
#define BARCODETYPE_EAN13   9
#define BARCODETYPE_EAN8    10
#define BARCODETYPE_UPCA    11
#define BARCODETYPE_UPCE    12
#define BARCODETYPE_25      13
#define BARCODETYPE_INTER25 14
#define BARCODETYPE_CODABAR 15
#define BARCODETYPE_PDF417  16
#define BARCODETYPE_DATAMTX 17
#define BARCODETYPE_USERDEF  18

#define BARCODEATTRIB_REVERSE          0x0008 //条码反转
#define BARCODEATTRIB_HUMANREAD        0x1000 //显示人识别字符
#define BARCODEATTRIB_CHECKNUM         0x0004 //需要校验码
#define BARCODEATTRIB_PDF417_SHORTMODE 0x0040 //PDF417为缩短模式
#define BARCODEATTRIB_DATAMTX_DOTMODE  0x0080 //DataMtrix为点模式
#define BARCODEATTRIB_CIRCLEMODE       0x0100 //自定义二维码为圆模式


#define DATAMTX_SIZEMODE_SMALLEST  0
#define DATAMTX_SIZEMODE_10X10     1
#define DATAMTX_SIZEMODE_12X12     2
#define DATAMTX_SIZEMODE_14X14     3
#define DATAMTX_SIZEMODE_16X16     4
#define DATAMTX_SIZEMODE_18X18     5
#define DATAMTX_SIZEMODE_20X20     6
#define DATAMTX_SIZEMODE_22X22     7
#define DATAMTX_SIZEMODE_24X24     8
#define DATAMTX_SIZEMODE_26X26     9
#define DATAMTX_SIZEMODE_32X32     10
#define DATAMTX_SIZEMODE_36X36     11
#define DATAMTX_SIZEMODE_40X40     12
#define DATAMTX_SIZEMODE_44X44     13
#define DATAMTX_SIZEMODE_48X48     14
#define DATAMTX_SIZEMODE_52X52     15
#define DATAMTX_SIZEMODE_64X64     16
#define DATAMTX_SIZEMODE_72X72     17
#define DATAMTX_SIZEMODE_80X80     18
#define DATAMTX_SIZEMODE_88X88     19
#define DATAMTX_SIZEMODE_96X96     20
#define DATAMTX_SIZEMODE_104X104   21
#define DATAMTX_SIZEMODE_120X120   22
#define DATAMTX_SIZEMODE_132X132   23
#define DATAMTX_SIZEMODE_144X144   24
#define DATAMTX_SIZEMODE_8X18     25
#define DATAMTX_SIZEMODE_8X32     26
#define DATAMTX_SIZEMODE_12X26     27
#define DATAMTX_SIZEMODE_12X36     28
#define DATAMTX_SIZEMODE_16X36     29
#define DATAMTX_SIZEMODE_16X48     30
//加入条码到数据库中
typedef int  (*LMC1_ADDBARCODETOLIB)(TCHAR* pStr,	//字符串
									  TCHAR* pEntName,//字符串对象名称
						 double dPosX, //字符左下角基点x坐标
						 double dPosY, //字符左下角基点y坐标
						 double dPosZ, //字符z坐标
						 int    nAlign,//对齐方式0－8
						 int    nPenNo,
						 int    bHatchText,
						 int    nBarcodeType,//条码类型
						 WORD   wBarCodeAttrib,//条码属性
						 double dHeight,//整个条码的高	
						 double dNarrowWidth,//最窄模块宽	
						 double dBarWidthScale[4],//条宽比例	(与最窄模块宽相比)
						 double dSpaceWidthScale[4],//空宽比例(与最窄模块宽相比)
						 double dMidCharSpaceScale,//字符间隔比例(与最窄模块宽相比)
						 double dQuietLeftScale,//条码左空白宽度比例(与最窄模块宽相比)
						 double dQuietMidScale,//条码中空白宽度比例(与最窄模块宽相比)
						 double dQuietRightScale,//条码右空白宽度比例(与最窄模块宽相比)	
						 double dQuietTopScale,//条码上空白宽度比例(与最窄模块宽相比)
						 double dQuietBottomScale,//条码下空白宽度比例(与最窄模块宽相比)						 
						 int    nRow,//二维码行数
						 int    nCol,//二维码列数
						 int    nCheckLevel,//pdf417错误纠正级别0-8
						 int    nSizeMode,//DataMatrix尺寸模式0-30
						 double dTextHeight,//人识别字符字体高度
						 double dTextWidth,//人识别字符字体宽度
						 double dTextOffsetX,//人识别字符X方向偏移
						 double dTextOffsetY,//人识别字符Y方向偏移
						 double dTextSpace,//人识别字符间距
						 double dDiameter,
						 TCHAR* pTextFontName);//文本字体名称

//更改当前数据库里的指定文本对象的文本
//输入参数: strTextName     要更改内容的文本对象的名称
//          strTextNew      新的文本内容
typedef int (*LMC1_CHANGETEXTBYNAME)(TCHAR* strTextName, TCHAR* strTextNew);


//设置旋转变换参数
//输入参数: dCenterX 旋转中心x坐标
//          dCenterY 旋转中心y坐标
//          dRotateAng 旋转角度(弧度值)
typedef void (*LMC1_SETROTATEPARAM)(double dCenterX,double dCenterY,double dRotateAng);


//////////////////////////////////////////////////////////////////
//扩展轴函数

//扩展轴移动到指定坐标位置
//输入参数: axis     扩展轴  0 = 轴0  1 = 轴1
//          GoalPos  坐标位置
typedef int    (*LMC1_AXISMOVETO)(int axis,double GoalPos);

//扩展轴校正原点
//输入参数: axis     扩展轴  0 = 轴0  1 = 轴1
typedef int    (*LMC1_AXISCORRECTORIGIN)(int axis);

//得到扩展轴的当前坐标
//输入参数: axis扩展轴  0 = 轴0  1 = 轴1
typedef double (*LMC1_GETAXISCOOR)(int axis);

//扩展轴移动到指定脉冲坐标位置
//输入参数: axis     扩展轴  0 = 轴0  1 = 轴1
//          nGoalPos  脉冲坐标位置
typedef int   (*LMC1_AXISMOVETOPULSE)(int axis,int nGoalPos);

//得到扩展轴的当前脉冲坐标
//输入参数: axis扩展轴  0 = 轴0  1 = 轴1
typedef int (*LMC1_GETAXISCOORPULSE)(int axis);


//复位扩展轴坐标
//输入参数:  bEnAxis0 = 使能轴0  bEnAxis1 = 使能轴1
typedef double (*LMC1_RESET)(BOOL bEnAxis0 , BOOL bEnAxis1);


//字体类型属性定义
#define FONTATB_JSF        0x0001        //JczSingle字型
#define FONTATB_TTF        0x0002        //TrueType字型   
#define FONTATB_DMF        0x0004        //DotMatrix字型   
#define FONTATB_BCF        0x0008        //BarCode字型  

//字型记录
struct lmc1_FontRecord
{  	
    TCHAR   szFontName[256];     //字体名字	    
    DWORD   dwFontAttrib;       //字体属性
};

//得到当前系统支持的所有字体参数
//输入参数: 无
//输出参数: nFontNum 字体数目
//返回参数: lmc1_FontRecord* 字体记录数组
typedef lmc1_FontRecord* (*LMC1_GETALLFONTRECORD)(int& nFontNum);

//保存当前数据库里所有对象到指定ezd文件里
//输入参数: strFileName ezd文件名称
typedef int (*LMC1_SAVEENTLIBTOFILE)(TCHAR* strFileName);

//得到指定对象的最大最小坐标,如果pEntName==NULL表示读取数据库所有对象的最大最小坐标
typedef int  (*LMC1_GETENTSIZE)(TCHAR* pEntName,//字符串对象名称
									 double& dMinx,
									 double& dMiny,
									 double& dMaxx,
									 double& dMaxy,
                                                                         double& dZ);

//移动指定对象相对坐标
typedef int  (*LMC1_MOVEENT)(TCHAR* pEntName,//字符串对象名称
								double dMovex,
								double dMovey);


//缩放指定对象，缩放中心坐标(dCenx，dCeny)  dScaleX=X方向缩放比例  dScaleY=Y方向缩放比例
typedef int  (*LMC1_SCALEENT)(TCHAR* pEntName,//字符串对象名称
				   double dCenx,
				   double dCeny,
				   double dScaleX,
				   double dScaleY);
//镜像指定对象，镜像中心坐标(dCenx，dCeny)  bMirrorX=TRUE X方向镜像  bMirrorY=TRUE Y方向镜像
typedef  int  (*LMC1_MIRRORENT)(TCHAR* pEntName,//字符串对象名称
				   double dCenx,
				   double dCeny,
				   BOOL   bMirrorX,
				   BOOL   bMirrorY);

//旋转指定对象，旋转中心坐标(dCenx，dCeny)  dAngle=旋转角度(逆时针为正，单位为度)
typedef  int  (*LMC1_ROTATEENT)(TCHAR* pEntName,//字符串对象名称
				   double dCenx,
				   double dCeny,
				   double dAngle);

typedef int  (*LMC1_REDLIGHTMARK)();//标刻一次红光显示框

//得到对象总数
//输出参数:  对象总数
typedef  int (*LMC1_GETENTITYCOUNT)();

//得到指定序号的对象名称
//输入参数: nEntityIndex 指定对象的序号(围: 0 － (lmc1_GetEntityCount()-1))
//输出参数: szEntName 对象的名称
typedef int (*LMC1_GETENTITYNAME)(int nEntityIndex,TCHAR  szEntName[256]);

//得到狗的客户ID号
typedef WORD (*LMC1_GETCLIENTID)();

//得到指定对象的文本
typedef int (*LMC1_GETTEXTBYNAME)(TCHAR* strTextName, TCHAR strText[256]);


//删除指定对象
typedef int  (*LMC1_DELETEENT)(TCHAR* pEntName);

//拷贝指定对象为新对象
typedef int (*LMC1_COPYENT)(TCHAR* strEntName,TCHAR* strNewEntName);

//改变指定对象的名字为strNewName
typedef int (*LMC1_CHANGEENTNAME)(TCHAR* strEntName,TCHAR* strNewName);



//直接开关激光
typedef int (*LMC1_LASERON)(BOOL bOpen);

//得到当前振镜坐标
typedef int (*LMC1_GETCURCOOR)(double& x,double& y);

//得到振镜直接跳转到指定坐标
typedef int (*LMC1_GOTOPOS)(double x,double y);

//设置PWM输出的脉冲周期和脉冲宽度
//wPulseHalfPeriod = 脉冲周期的一半 ，单位US
//wPulseWidth = 脉冲的高电平宽度 ，单位US
typedef int (*LMC1_SETPWM)(WORD wPulseHalfPeriod,WORD wPulseWidth);

//设置IPG激光器的输出功率0-100%
typedef int (*LMC1_SETIPGPOWER)(double dRatio);


//在指定位置标刻一条线
typedef int (*LMC1_MARKLINE)(double x1,double y1,double x2,double y2,int pen);
typedef int (*LMC1_MARKLINE2)(double x1,double y1,double x2,double y2,double dSpeed,double dPowerRatio,int nFreq);
//在指定位置标刻一个点
typedef int (*LMC1_MARKPOINT)(double x,double y,double delay,int pen);
#endif