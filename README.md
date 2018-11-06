# EzCad_Dev_Dome
A EzCad laser mark develop dome whit EzCad 2.7.0 in C#


# 1. 概述
MarkEzd.dll 是北京金橙子科技有限公司提供给用户用于ezcad2和lmc1控制卡二次开发的动态连接库。  

MarkEzdDll.h是MarkEzd.dll中输出的函数的头文件。用户可以使用VC6.0来进行开发。  
  
MarkEzd.dll动态链接库函数的调用方法为显示调用,显式调用方法需要调用Windows API函数加载和释放动态链接库。  

## 显式调用方法如下：

1.调用Windows API函数LoadLibrary()动态加载DLL；

2.调用Windows API函数GetProcAddress()取得将要调用的DLL中函数的指针；用函数指针调用DLL中函数完成相应功能；

3.在程序结束时或不再使用DLL中函数时，调用Windows API函数FreeLibrary()释放动态链接库。

注意：调用MarkEzd.dll的程序必须放在ezcad2.exe同一个目录下，否则MarkEzd.dll将无法正常工作；而且ezcad2.exe在运行的时候MarkEzd.dll将无法正常使用，所以在使用MarkEzd.dll时必须关闭ezcad2.exe。

# 2.函数说明
在MarkEzd.dll中所有函数（个别函数除外）返回值均为一个整形的通用错误码

##通用错误码定义如下：

\#define LMC1_ERR_SUCCESS         0  //成功

\#define LMC1_ERR_EZCADRUN        1  //发现EZCAD在运行

\#define LMC1_ERR_NOFINDCFGFILE   2  //找不到EZCAD.CFG

\#define LMC1_ERR_FAILEDOPEN      3  //打开LMC1失败

\#define LMC1_ERR_NODEVICE        4  //没有有效的lmc1设备

\#define LMC1_ERR_HARDVER         5  //lmc1版本错误

\#define LMC1_ERR_DEVCFG          6  //找不到设备配置文件

\#define LMC1_ERR_STOPSIGNAL      7  //报警信号

\#define LMC1_ERR_USERSTOP        8  //用户停止

\#define LMC1_ERR_UNKNOW         9  //不明错误

\#define LMC1_ERR_OUTTIME         10 //超时

\#define LMC1_ERR_NOINITIAL       11 //未初始化

\#define LMC1_ERR_READFILE        12 //读文件错误

\#define LMC1_ERR_OWENWNDNULL     13 //窗口为空

\#define LMC1_ERR_NOFINDFONT      14 //找不到指定名称的字体

\#define LMC1_ERR_PENNO           15 //错误的笔号

\#define LMC1_ERR_NOTTEXT         16 //指定名称的对象不是文本对象

\#define LMC1_ERR_SAVEFILE        17 //保存文件失败

\#define LMC1_ERR_NOFINDENT           18 //找不到指定对象

\#define LMC1_ERR_STATUE        19 //当前状态下不能执行此操作

注意：MarkEzd.dll中所有函的TCHAR对象都必须是UNICODE字符。关于如何把项目设置为UNICODE版请参考附录一。



##函 数 名：lmc1_Initial

###目    的：初始化lmc1控制卡。

###语    法：`int lmc1_Initial（TCHAR* strEzCadPath,BOOL bTestMode,HWND hOwenWnd）；`

- strEzCadPath是ezcad2.exe所处的目录的全路径名称；

- bTestMode  指是否是测试模式

- hOwenWnd 指拥有用户输入焦点的窗口，用于检测用户暂停消息。

###描    述：在程序中必须首先调用lmc1_Initial，其它函数才能工作。

###返 回 值：通用错误码

 

##函 数 名：lmc1_Close

###目    的：关闭lmc1控制卡。

###语    法：`int lmc1_Close（）；`

###描    述：在程序中退出时必须调用lmc1_Close来关闭lmc1控制卡。

###返 回 值：通用错误码

 

##函 数 名：lmc1_LoadEzdFile

####语    法：`int lmc1_LoadEzdFile(TCHAR* strFileName);`

###描    述：在程序中一般用此函数来打开一个用户建立ezd模板文件，这样用户就不需要在程序中设置加工参数，因为模板中的加工参数会自动导入。

###返 回 值：通用错误码

 

##函 数 名：lmc1_Mark

###目    的：标刻当前数据库里的所有数据。

###语    法：`int lmc1_Mark（BOOL bFlyMark）；`

- bFlyMark= TRUE 使能飞动打标

###描    述：在使用lmc1_LoadEzdFile载入ezd文件后即可以使用此函数开始打标加工，此函数一直等待设备加工完毕后才返回。

###返 回 值：通用错误码



 

##函 数 名：lmc1_ChangeTextByName

###目    的：更改指定名称的文本对象的文本内容。

###语    法：`int lmc1_ChangeTextByName(TCHAR* strTextName, TCHAR* strTextNew)；`

- strTextName     要更改内容的文本对象的名称

- strTextNew      新的文本内容

 

###描    述：在使用lmc1_LoadEzdFile载入ezd文件后，在每次加工前即可以使用此函数更改指定对象的内容。

###返 回 值：通用错误码
  
 

##函 数 名：lmc1_MarkEntity

###目    的：标刻当前数据库里的指定名称的对象。

###语    法：`int lmc1_MarkEntity（TCHAR* strEntName）；`

###描    述：在使用lmc1_LoadEzdFile载入ezd文件后即可以使用此函数开始加工指定名称的对象，此函数一直等待设备加工完毕后才返回。

###返 回 值：通用错误码

 

##函 数 名：lmc1_ReadPort

###目    的：读lmc1的输入端口。

##语    法：`int lmc1_ReadPort（WORD& data）；`

- data 输入端口的数据

###描    述：在程序中调用lmc1_ReadPort来读入当前输入端口的数据。

###返 回 值：通用错误码

 

##函 数 名：lmc1_WritePort

###目    的：写lmc1的输出端口。

###语    法：`int lmc1_WritePort（WORD data）；`

- data 输出端口的数据

###描    述：在程序中调用lmc1_WritePort来输出数据到当前输出端口。

###返 回 值：通用错误码

 

##函 数 名：lmc1_GetPrevBitmap

###目    的：得到当前数据库里的所有对象的预览图像。

###语  法：`Cbitmap* lmc1_GetPrevBitmap（HWND hwnd,int nBMPWIDTH,int nBMPHEIGHT）；`

- hwnd需要显示当前图像的窗口句柄

- nBMPWIDTH 需要生成的图像的像素宽度

- nBMPHEIGHT需要生成的图像的像素高度

###描    述：在程序中调用lmc1_GetPrevBitmap得到当前数据库里的所有对象的预览图像，可以用于更新界面显示。

###返 回 值：如果成功会返回图像，返回值为空表示失败

 

##函 数 名：lmc1_SetDevCfg

###目    的：设置设备参数

###语    法：`int lmc1_SetDevCfg（）；`

###描    述：调用lmc1_SetDevCfg会自动弹出设备参数设置对话框，用户可以设置设备参数。

###返 回 值：通用错误码

 

##函 数 名：lmc1_SetHatchParam

###目    的：设置当前填充参数。

###语    法：
	int lmc1_SetHatchParam（BOOL   bEnableContour,//使能轮廓本身
							int    bEnableHatch1,//使能填充1
							int    nPenNo1,//填充笔
							int    nHatchAttrib1,//填充属性
							double dHatchEdgeDist1,//填充线边距
							double dHatchLineDist1,//填充线间距
							double dHatchStartOffset1,//填充线起始偏移距离
							double dHatchEndOffset1,//填充线结束偏移距离
							double dHatchAngle1,//填充线角度 (弧度值)
							int    bEnableHatch2,//使能填充1
							int    nPenNo2,//填充笔
							int    nHatchAttrib2,//填充属性
							double dHatchEdgeDist2,//填充线边距
							double dHatchLineDist2,//填充线间距
							double dHatchStartOffset2,//填充线起始偏移距离
							double dHatchEndOffset2,//填充线结束偏移距离
							double dHatchAngle2);//填充线角度 (弧度值)
							）；

- bEnableContour 是否使能轮廓

- bEnableHatch1  使能填充

- nPenNo1       填充笔号

- nHatchAttrib1   填充属性，填充属性由下面几个属性相或组合

- const int HATCHATTRIB_ALLCALC = 0x01;//全部对象作为整体一起计算

- const int HATCHATTRIB_BIDIR   = 0x08;//双向填充

- const int HATCHATTRIB_EDGE    = 0x02;//走一次边

- const int HATCHATTRIB_LOOP    = 0x10;//环形填充

- dHatchEdgeDist1   填充线边距

- dHatchLineDist1    填充线间距

- dHatchStartOffset1  填充线起始偏移距离

- dHatchEndOffset1  填充线结束偏移距离

- dHatchAngle1     填充线角度 (弧度值)

- 填充2参数意义同填充1参数一样。

###描    述：在程序中调用lmc1_SetHatchParam来设置当前填充参数，当下次向数据库添加对象使能填充时，即使用此填充参数。

###返 回 值：通用错误码

 

##函 数 名：lmc1_SetFontParam

###目    的：设置当前默认的字体参数。

###语    法：
	 int lmc1_SetFontParam（TCHAR* strFontName
							double dCharHeight,
							double dCharWidth,
							double dCharAngle,
							double dCharSpace,
							double dLineSpace,
							BOOL   bEqualCharWidth）；

- StrFontName  字体名称

- dCharHeight   字符高度

- dCharWidth   字符宽度

- dCharAngle   字符倾角

- dCharSpace   字符间距

- dLineSpace    行间距

- bEqualCharWidth  等字符宽度模式

###描    述：在程序中调用lmc1_ SetFontParam来设置当前字体参数，当下次向数据库添加文本对象时即使用此字体参数来生成文本对象。

###返 回 值：通用错误码

 

##函 数 名：lmc1_GetPenParam

###目    的：得到对应笔号的参数。

###语    法：
	   int lmc1_GetPenParam（int      nPenNo,//要设置的笔号(0-255)    
							int       nMarkLoop,//加工次数
							double&   dMarkSpeed,//标刻次数mm/s
							double&   dPowerRatio,//功率百分比(0-100%)
							double&   dCurrent,//电流A
							int&      nFreq,//频率HZ
							int&      nQPulseWidth,//Q脉冲宽度us
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
							double&   dFlySpeed）；//流水线速度

###描    述：在程序中调用lmc1_GetPenParam来读出数据库中对应笔号的参数。

###返 回 值：通用错误码

 

##函 数 名：lmc1_SetPenParam

###目    的：设置设备参数

###语    法：
	  int lmc1_SetPenParam（int      nPenNo,//要设置的笔号(0-255)  
							int      nMarkLoop,//加工次数
							double   dMarkSpeed,//标刻次数mm/s
							double   dPowerRatio,//功率百分比(0-100%)
							double   dCurrent,//电流A
							int      nFreq,//频率HZ
							int      nQPulseWidth,//Q脉冲宽度us
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
							int      nPulseNum, //脉冲点数目
							double   dFlySpeed); //流水线速度s

###描    述：在程序中调用lmc1_SetPenParam来设置数据库中对应笔号的参数。

###返 回 值：通用错误码

 

##函 数 名：lmc1_ClearEntLib

###目    的：清除对象库里所有对象。

###语    法：`int lmc1_ClearEntLib（）；`

###描    述：在程序中调用lmc1_ ClearEntLib来清除对象库里所有对象。

###返 回 值：通用错误码

 

##函 数 名：lmc1_AddTextToLib

###目    的：加入新文本到数据库中。

###语    法：
	 int lmc1_AddTextToLib（TCHAR* pStr,
							TCHAR* pEntName,
							double dPosX,
							double dPosY,
							double dPosZ,
							int    nAlign
							double dTextRotateAngle,
							int nPenNo,
							BOOL bHatchText);//是否填充文本对象

- pStr      要添加的字符串

- pEntName 字符串对象名称

- dPosX    字符串的左下角基点的x坐标

- dPosY    字符串的左下角基点的y坐标

- dPosZ    字符串对象的z坐标

- nAlign    对齐方式0－8

		//对齐方式时数字代表的意义
		
		  6 -----  5 ----- 4
		
		  |                |
		
		  |                |
		
		  7       8        3
		
		  |                |
		
		  |                |
		
		  0 ------ 1  -----2

- dTextRotateAngle  字符串绕基点旋转的角度值(弧度值)

- nPenNo          文本对象使用的笔号

- bHatchText       是否填充文本对象

 

###描    述：在程序中调用lmc1_AddTextToLib加入新文本对象到数据库中。

###返 回 值：通用错误码

 

##函 数 名：lmc1_AddCurveToLib

###目    的：加入曲线到数据库中。

###语    法：
		int lmc1_AddCurveToLib（double ptBuf[][2],//曲线顶点数组
								int    ptNum,//曲线顶点数
								TCHAR* pEntName,//曲线对象名称
								int    nPenNo,//曲线对象使用的笔号
								int    bHatch);//曲线是否填充

###描    述：在程序中调用lmc1_AddCurveToLib加入曲线对象到数据库中。

###返 回 值：通用错误码

 

##函 数 名：lmc1_AddFileToLib

###目    的：加入指定文件到数据库中。

###语    法：
	 int lmc1_AddFileToLib（TCHAR* pFileName, //文件名称
							TCHAR* pEntName,// 文件对象名称
							double dPosX, //文件左下角基点x坐标
							double dPosY, //文件左下角基点y坐标
							double dPosZ, //文件z坐标
							int    nAlign,//对齐方式0－8
							double dRatio,//文件缩放比例   
							int    nPenNo,//对象使用的加工参数
							BOOL   bHatchFile);

- pFileName要添加的文件名称，支持的文件格式有ezd,dxf,dst,plt,ai,bmp,jpg,tga,png,gif,tiff等

- pEntName 文件对象名称

- dPosX    文件的左下角基点的x坐标

- dPosY    文件的左下角基点的y坐标

- dPosZ    文件对象的z坐标

- nAlign    对齐方式0－8

- dRatio    文件缩放比例   

- nPenNo   文件对象使用的笔号

- bHatchFile  是否填充文件对象

###描    述：在程序中调用lmc1_AddFileToLib加入新文件对象到数据库中。

###返 回 值：通用错误码

 

##函 数 名：lmc1_AddBarCodeToLib

###目    的：增加条码对象到数据库里。

###语    法：
	   int lmc1_AddBarCodeToLib(TCHAR* pStr,
								TCHAR* pEntName,
								double dPosX,
								double dPosY,
								double dPosZ,
								int    nAlign,
								int    nPenNo,
								int    bHatchText,
								int    nBarcodeType,
								WORD   wBarCodeAttrib,
								double dHeight,
								double dNarrowWidth,
								double dBarWidthScale[4],
								double dSpaceWidthScale[4],
								double dMidCharSpaceScale,
								double dQuietLeftScale,
								double dQuietMidScale,
								double dQuietRightScale,
								double dQuietTopScale,
								double dQuietBottomScale,
								int    nRow,
								int    nCol,
								int    nCheckLevel,
								int    nSizeMode,
								double dTextHeight,
								double dTextWidth,
								double dTextOffsetX,
								double dTextOffsetY,
								double dTextSpace,
								TCHAR* pTextFontName);

 

 - pStr 条码表示的字符串

 - pEntName  条码对象名称

 - dPosX,  条码左下角基点x坐标

 - dPosY  条码左下角基点y坐标

 - dPosZ  条码z坐标

 - nAlign, 对齐方式0－8

 - nPenNo   使用的笔号

 -  bHatchText  是否填充条码

 - nBarcodeType  条码类型

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

-  wBarCodeAttrib 条码属性

		#define BARCODEATTRIB_REVERSE          0x0008 //条码反转
		#define BARCODEATTRIB_HUMANREAD        0x1000 //显示人识别字符
		#define BARCODEATTRIB_CHECKNUM         0x0004 //需要校验码
		#define BARCODEATTRIB_PDF417_SHORTMODE 0x0040 //PDF417为缩短模式
		#define BARCODEATTRIB_DATAMTX_DOTMODE  0x0080 //DataMtrix为点模式

 

- dHeight        整个条码的高

- dNarrowWidth  最窄模块宽

- dBarWidthScale 条宽比例(与最窄模块宽相比)

- dSpaceWidthScale 空宽比例(与最窄模块宽相比)

- dMidCharSpaceScale  字符间隔比例(与最窄模块宽相比)

- dQuietLeftScale  条码左空白宽度比例(与最窄模块宽相比)

- dQuietMidScale  条码中空白宽度比例(与最窄模块宽相比)

- dQuietRightScale 条码右空白宽度比例(与最窄模块宽相比)

- dQuietTopScale  条码上空白宽度比例(与最窄模块宽相比)

- dQuietBottomScale 条码下空白宽度比例(与最窄模块宽相比) nRow  二维码行数

- nCol  二维码列数

- nCheckLevel,//pdf417错误纠正级别0-8

- nSizeMode,//DataMatrix尺寸模式0-30

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
		#define DATAMTX_SIZEMODE_8X18      25
		#define DATAMTX_SIZEMODE_8X32      26
		#define DATAMTX_SIZEMODE_12X26     27
		#define DATAMTX_SIZEMODE_12X36     28
		#define DATAMTX_SIZEMODE_16X36     29
		#define DATAMTX_SIZEMODE_16X48     30

 

- dTextHeight人识别字符字体高度

- dTextWidth人识别字符字体宽度

- dTextOffsetX人识别字符X方向偏移

- dTextOffsetY 人识别字符Y方向偏移

- dTextSpace  人识别字符间距

- pTextFontName 文本字体名称

 

###描    述：在程序中调用lmc1_ AddBarCodeToLib增加条码对象到数据库里。

###返 回 值：通用错误码

 

##函 数 名：lmc1_SetRotateParam

###目    的：设置旋转变换参数。

###语    法：`int lmc1_SetRotateParam（double dCenterX,double dCenterY,double dRotateAng）；`

- dCenterX 旋转中心x坐标

- dCenterY 旋转中心y坐标

- dRotateAng 旋转角度(弧度值)

###描    述：在程序中调用lmc1_ SetRotateParam来设置旋转变换参数，使数据库中所有对象绕指定中心旋转。

###返 回 值：通用错误码

 

##函 数 名：lmc1_AxisMoveTo

###目    的：扩展轴移动到指定坐标位置。

###语    法： `int lmc1_AxisMoveTo（int axis,double GoalPos）；`

- axis     指定要运动的扩展轴号  0 = 轴0  1 = 轴1

- GoalPos  坐标绝对位置

###描    述：在程序中调用lmc1_ AxisMoveTo可以使扩展轴移动到指定坐标位置，扩展轴的运动速度使用设备参数里定义的最大速度。

###返 回 值：通用错误码

 

##函 数 名：lmc1_AxisCorrectOrigin

###目    的：扩展轴校正原点。

###语    法：`int lmc1_AxisCorrectOrigin（int axis）；`

- axis     指定要校正原点的扩展轴号  0 = 轴0  1 = 轴1

###描    述：在程序中调用lmc1_ AxisCorrectOrigin可以使扩展轴自动校正原点。

###返 回 值：通用错误码

 

##函 数 名：lmc1_GetAxisCoor

###目    的：得到扩展轴的当前坐标。

###语    法：`int lmc1_GetAxisCoor（int axis）；`

- axis     指定的扩展轴号  0 = 轴0  1 = 轴1

###描    述：在程序中调用lmc1_ GetAxisCoor得到扩展轴的当前坐标。

###返 回 值：扩展轴的当前坐标

 

##函 数 名：lmc1_Reset

###目    的：复位扩展轴坐标。

###语    法：`int lmc1_Reset（BOOL bEnAxis0 , BOOL bEnAxis1）；`

- bEnAxis0    是否使能扩展轴号  0

- bEnAxis1    是否使能扩展轴号  1

###描    述：在程序中调用扩展轴相关的函数，必须先调用lmc1_Reset来设置使能对应的轴，当扩展轴运动到极限位置时，可以用此函数复位扩展轴坐标。

###返 回 值：通用错误码

 

##函 数 名：lmc1_GetAllFontRecord

###目    的：得到当前系统支持的所有字体参数。

###语    法：`lmc1_FontRecord* lmc1_GetAllFontRecord（int nFontNum）；`

	nFontNum 字体数目
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

 

###描    述：得到当前系统支持的所有字体参数。

###返 回 值：字型记录数组指针

 

##函 数 名：lmc1_SaveEntLibToFile

###目    的：保存当前数据库里所有对象到指定ezd文件里。

###语    法：`int lmc1_SaveEntLibToFile（TCHAR* strFileName）；`

- strFileName    ezd文件名称

###描    述：保存当前数据库里所有对象到指定ezd文件里。

###返 回 值：通用错误码

 

##函 数 名：lmc1_GetEntSize

###目    的：得到指定对象的最大最小坐标。

###语    法：
	int lmc1_GetEntSize（TCHAR* pEntName,
						double  dMinx,
						double  dMiny,
						double  dMaxx,
						double  dMaxy ,
						double  dZ）；

- pEntName 对象名称

- dMinx  最小x坐标

- dMiny  最小y坐标

- dMaxx  最大x坐标

- dMaxy  最大y坐标

- dZ     对象的Z 坐标

###描    述：得到指定对象的最大最小坐标。
###返 回 值：通用错误码

 

##函 数 名：lmc1_MoveEnt

###目    的：指定对象移动相对位置。

###语    法：`int lmc1_GetEntSize（TCHAR* pEntName, double dMovex, double dMovey）；`

- pEntName 对象名称
- dMovex  对象移动的x坐标
- dMovey  对象移动的y坐标

###描    述：指定对象移动相对位置。

###返 回 值：通用错误码

 

##函 数 名：lmc1_RedLightMark

###目    的：标刻一次红光显示框。

###语    法：`int lmc1_RedLightMark（）；`

###描    述：标刻一次红光显示框。

###返 回 值：通用错误码

 

##函 数 名：lmc1_MarkLine

###目    的：标刻指定线段。

###语    法：

	 int lmc1_MarkLine（double x1,
						double y1
						double x2,
						double y2,
						int    pen）；

- x1,y1起点坐标

- x2,y2终点坐标

- pen 使用的笔号

###返 回 值：通用错误码

##函 数 名：lmc1_MarkPoint

###目    的：标刻指定点。

###语    法：`int lmc1_MarkPoint（double x, double y, double delay, int pen）；`

- x,y点坐标
- delay打点时间
- pen 使用的笔号

###描    述：在指定位置打点

###返 回 值：通用错误码

##函 数 名：lmc1_GetCurCoor

###目    的：得到当前振镜坐标。

###语    法：`int lmc1_GetCurCoor（double& x, double& y）；`

- x,y 点坐标
- delay 打点时间
- pen 使用的笔号

###描    述：得到当前振镜坐标

###返 回 值：通用错误码

 

##函 数 名：lmc1_GetEntityCount

###目    的：得到当前数据库中的对象总数。

###语    法：`int lmc1_GetEntityCount（）；`

###描    述：得到当前数据库中的对象总数

###返 回 值：数据库内对象总数

 

##函 数 名：lmc1_GetEntityName

###目    的：得到指定序号的对象名称。

###语    法：`int lmc1_GetEntityName（int nEntityIndex, TCHAR szEntName[256]）；`

- nEntityIndex指定序号，范围值为 0－对象总数（对象总数由函数lmc1_GetEntityCount得到）
- szEntName得到的对象名称

###描    述：得到指定序号的对象名称

###返 回 值：通用错误码

 

 

##函 数 名：lmc1_AddPointToLib

###目    的：向数据库添加一组点对象。

###语    法：`int lmc1_AddPointToLib(double[,] PtBuf,int ptNum,string strEntName,int nPenNo)；`

- PtBuf点位置的二维数组，第一为必须为2，如double[n,2]
- ptNum点位置的个数
- szEntName得到的对象名称
- nPenNo添加点的笔号

###描    述：向数据库添加一组点对象

###返 回 值：通用错误码

 

 

##函 数 名：lmc1_ StopMark

###目    的：停止标刻

###语    法：`int lmc1_ StopMark()；`

###描    述：调用lmc1_ StopMark会停止标刻。

###返 回 值：通用错误码



#3.开发步骤(仅适用于VC++，本工程采用C#编写，以下仅供参考)
下面我们结合一个实例来讲解如何进行二次开发。

客户要求在一个矩形工件中心加工一行文本（如下图所示），每个工件要加工的文本都必须从网络服务器上去在线查询获得。

用户要进行二次开发一般的步骤如下：

##1．建立模板文件
先用ezcad2建立一个模板文件test.ezd，然后新建一个文本对象，把文本对象命名为”name”。然后调节文本大小，位置和加工参数使加工效果达到客户要求，此时保存文件并退出ezcad2。

 

##2． 编写专用软件调用MarkEzd.dll动态链接库

###第一步：.动态加载MarkEzd.dll

HINSTANCE hEzdDLL = LoadLibrary(_T("MarkEzd.dll"));

 

###第二步：.取得将要调用的DLL中函数的指针

lmc1_Initial=(LMC1_INITIAL)GetProcAddress(hEzdDLL, _T("lmc1_Initial"));

lmc1_Close=(LMC1_CLOSE)GetProcAddress(hEzdDLL, _T("lmc1_Close")); lmc1_LoadEzdFile=(LMC1_LOADEZDFILE)GetProcAddress(hEzdDLL,_T("lmc1_LoadEzdFile"));

lmc1_Mark=(LMC1_MARK)GetProcAddress(hEzdDLL,_T("lmc1_Mark"));

lmc1_ChangeTextByName=(LMC1_CHANGETEXTBYNAME)GetProcAddress(hEzdDLL,_T("lmc1_ChangeTextByName"));

###第三步：用函数指针调用DLL中函数完成相应功能

 

1）初始化lmc1控制卡  lmc1_Initial（）

2）打开test.ezd  lmc1_LoadEzdFile(_T(“test.ezd”))。

3）从网络服务器上去在线查询获得要加工的文本 （需要用户自己编写这段程序）

4）更新更改指定名称的文本对象的文本内容

假设上一步取得的文本是“1234567”

lmc1_ChangeTextByName（_T(“name”)，_T(“1234567”) ）；

5）调用lmc1_Mark加工

6）如果还要加工则返回第3步继续。

7）关闭lmc1控制卡 lmc1_Close（）；

 

###第四步：

调用Windows API函数释放动态链接库。

FreeLibrary(hEzdDLL)
