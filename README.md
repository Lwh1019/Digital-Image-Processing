# Digital-Image-Processing
PhotoSystem based on Visual Studio MFC , Opencv ,Dlib ,Opencv-Contrib    based On C++

文件中有一些model都是用图片显示名字的，需要自行下载；  使用的时候 opencv_world490d.dll 库都要配好


数字图像处理技术 课  

一、Photo-solve  图像美化系统  

（1） 具有读取、显示和存储的图像文件，文件类型可以包括 BMP 文件、JPG 文件和 png 文件，包括彩色图像和灰度图像。

（2） 具有对图像进行预处理的功能：（1）加噪、去噪等功能。去噪方法包含多种空域滤波和多种频域滤波。（2）彩色变灰度功能。（3）具有裁剪功能，根据需要把需要的位置裁剪出来。

（3） 具有对图像进行基本几何变换的功能，具有旋转、对称和缩放，缩放需要考虑插值方法。

（4） 具有图片增强功能，包括直方图均衡化处理，调整亮度、对比度和饱和度等

（5） 具有图片美化处理功能，包括：加框、简单拼图、虚化、浮雕等

（6） 图像特殊功能，例如超分辨率、照片复原、图像相似度分析、图像风格转换算法(style transfer)

UI 展示：

![image](https://github.com/user-attachments/assets/edc3ff0b-6a32-4aa2-80d7-73aa284f59ca)

效果演示（以风格化转移为例）：

![image](https://github.com/user-attachments/assets/d74885b1-9fd2-401e-ae57-f168426d63b8)


二、Photo-idf  图像识别系统 

（1） 具有读取、显示和存储图像文件的功能，文件类型可以包括BMP 文件、JPG 文件和png文件，包括彩色图像和灰度图像。具有从摄像头直接抓取图像功能。

（2） 具有对图像进行预处理的功能，包含形态学处理的两种方法、特定目标特征测量方法3种。

（3） 具有对图像进行特定分割的功能，实现区域生长、边缘检测（梯度算子）和阈值分割各多种方法。

（4） 具有对输入包含人脸的图像进行人脸检测和处理的功能，实现：

a) 识别人脸区域，并以类似图1-（b）形式显示，明显表达人脸区域的方式显示。

b) 具有对人脸进行编辑的功能，例如进行人脸风格化表示、人脸化妆、换脸

UI 展示：

![image](https://github.com/user-attachments/assets/89dfc9ab-5e34-4bbf-ac98-e3c27a6c6079)

效果演示（以换脸为例）：

![image](https://github.com/user-attachments/assets/e9627b32-6632-4a22-abf5-3d22049c5ea9)

三、Photo-color  图像色彩处理和拼接系统 

（1） 具有读取、显示和存储图像文件功能，文件类型可以包括BMP 文件、JPG 文件和png文件，包括彩色图像和灰度图像。

（2） 具有对图像色彩模型和图像类型进行转换的功能，至少包含RGB和HSI转换、彩色图像转灰度、彩色图像转二值图的功能。

（3） 具有实现假彩色增强、伪彩色增强功能。

（4） 具有对任意2张及以上的相关图像进行拼接处理的功能：

a) 待拼接的图片可以自行交互选择。

b) 拼接的方法至少2种，可以考虑采用先进论文的算法复现。

c) 拼接的图像在重叠部分需要优化，即需要考虑融合方法。融合的方法至少2种，并且可以交互选择。

UI 展示：

![image](https://github.com/user-attachments/assets/d370eb51-14bb-4d5c-862b-c2a25882b0c1)


效果演示（以Stitch类拼接为例）：

![image](https://github.com/user-attachments/assets/3f868c26-eb52-4482-aa7f-e3b65c90848e)












