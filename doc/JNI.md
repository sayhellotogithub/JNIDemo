##什么是JNI

java native interface,java本地接口，实现让java和本地语言c/C++之间的相互调用。jni是一种协议，提供的一套编程框架

##为什么需要jni
1.操作底层硬件，android手机上的传感器
2.程序的运行效率高，2d3d加速，音视频的解码
3.程序的安全性
4.复用本地开源项目，SQLite,OpenSSL,OpenGL，OpenCV,FFmpeg
5.复用公司之前本地项目,游戏从PC端往移动端移植

JNI缺点
降低了程序可以移植性

##使用JNI的前提
*熟练使用Java
*了解基本c语言
*熟悉jni规范
*会使用NDK

##基本数据类型

java中的数据类型               C语言的数据类型
boolean 1					 没有对应的类型，c语言中非0为真，0为假 0.5逻辑真

byte 1							需要转换					  

char 2							char 1
short 2							short 2					
int 4							int 4
long 8							long 4,但是可以使用long long 8
float 4							float 4
double 8						double 8
								unsigned
								signed

1.c语言中没有byte,boolean;
c语言中非0为真，0为假 0.5逻辑真

2.c语言中的char和long与java不同

3.c语言中整数类型前面有signed/unsigned,影响是否能表示负数。默认为signed

4.sizeof（）运算符计算数据大小

###输出

	//int
	printf("%d\n",120);
	//无符号整数 
	printf("%u\n",120);
	//八进制数 
	printf("%o\n",0120);
	printf("%#o\n",0120);
	//十六进制数 
	printf("%#x\n",0x120);
	printf("%x\n",0x120);
	//输出字符 
	printf("%c:%d\n",'a','a');
	//输出字符串 
	printf("%s\n","dfefefe");
	//long 
	printf("%ld\n",22323);
	//double 
	printf("%lf\n",21323.9089);
	//short 
	printf("%hd\n",123);

###输入
	int a;
	scanf("%d",&a);

#指针
##内存特点
*内存单元大小 1byte=8bits,内存单元的排列是线性连续
*进程内存单元个数(内存大小)，在32位平台下，每个进程拥有4G内存范围，
可用的内存范围是4G
1k=1024bytes
4G=4*1024*1024*1024*8 bit
  =4*2014*1024*1024bytes=2^32
##内存单元的编号
*操作系统给每个内存单元一个唯一编号，从0开始连续编号直到4G-1
##指针
指针：
printf("&i=%p\n",&i);
将内存单元的地址(编号）称为指针
##指针运算符&*
*&取地址运算符，取变量的地址
**指针运算符（取对象运算符),取地址单元对应的相应的数据

变量的首地址&i
*&i 相当于i

##变量
*普通变量：保存数值数据
*指针变量：保存地址的变量

int i;
int *p=&i;//定义指针变量，*是类型标志，不是指针运算符
//int *p; p=&i;
*p=&i;

###*三种含义
指针运算符
定义指针变量
乘法

###指针的大小
*在32位平台下，指针大小为4个字节,因为内存编号就是4个字节32位
###指针的数据类型有什么作用
数据类型 * 变量
既然指针的数据类型不影响指针大小，那为什么要定义不同的数据类型
原因在于，指针所要访问的数据长度是由数据类型长度决定的，数据类型是指针所指向的对象类型
，如数据类型 int,与char 指针访问的数据及处理方式是不同的。
###指针类型
*指针类型：数据类型 * 合起来才是真正指针类型，在一个平台是确定的

###指针常见错误
* 指针的混用

	char a,*pa;
	int c,*pc;
	pa=(char *)&c;//强转还是有意义的
	pc=(int *)&a;//强转没有意义

* 野指针
 产生原因，使用指针之前没有合法指向

	    double a,*pa;
	    *pa=3.14;//会报错

  如果没有合法指向，建议NULL


### 二级指针
int **ptr,*pa,a;
pa=&a;
*ptr=pa;
**ptr=12;

###指针的运算
* 指针加整数N,向高地址方向移动N个对象，编号变化ptr+N*sizeof(对象类型)
* 指针减整数N，向低地址方向移动N个对象，编号变化ptr-N*sizeof(对象类型)


##数组
* 数组：相同数据类型变量的集合，变量在内存相邻连续排列
* 定义数组：
	* 数据类型 数组名[整形常量指定元素个数];
* 数组名：数组名代表数组首元素首地址，是一个常量不可更改
* 数组元素个数计算方法 sizeof(a)/sizeof(a[0])
* 
		int arr[5]={1,2,3,4,5};
		printf("a size %d",sizeof(arr)/sizeof(arr[0]));


##指针与数组的关系

	 int a[5]={1,2,3,4,5};
	 int *p;
	 p=a;
	 p[0];//相当于a[0]

## C语言中字符串
* c语言中用字符数组char buf[6]保存字符串，但需要在最后保存一个结束标志 '\0',实际存的的只有5个
* C语言中使用字符指针char *p=buf 保存字符串首元素首地址
* C语言中的字符串处理由string库函数，string.h
###字符串使用
char buf[6]={'h','e','l','l','0','\0'};
char buf[6]={"hello"};
char buf[]="hello";
sizeof(buf);//字符串容量
strlen(buf);//字符串长度，不包括结束标志
strcmp(,);//比较字符串



##void 指针

		int *p;
		char *q;
		void *s;
		s=p;
		q=s;

void *指针变量可以接收任意指针类型的值
void *指针可以指向任意指针类型赋值

##动态申请堆内存

	#include <stdio.h>
	#include <stdlib.h>
	
	int main(){
		int num;
		printf("请输入要申请的数组长度");
		scanf("%d",&num);
		
		int *ptr=(int *)malloc(num*sizeof(int)) ;
		int i=0;
		for(i=0;i<num;i++){
			scanf("%d",&ptr[i]);
		}
		free(ptr);//释放堆区空间 
		ptr=NULL;
		return 0;
	} 

int *p;
p=(sizeof(int *))malloc(4);

##结构体

	#include <stdio.h>
	struct Student{
		int age;
		float score;
		char buf[12];
	};
	int main(){
		struct Student stu;
		struct Student *ptr=&stu;
		struct Student * *ptrs=&ptr;
		
		stu.age=12;	
		stu.buf[0]='a';
		stu.buf[1]='b';
	
		stu.score=12.00;
		printf("%d\n",stu.age);
		printf("%d\n",(*ptr).age);
		printf("%d\n",ptr->age);
		printf("%d\n",(*ptrs)->age);
	} 

##共用体

共用体空间大小，所有成员共用同一段空间，由占用空间最大的决定
一次只用使用一个,因为一次只有一个成员有效

		union Un{
		  int a;
		  float b;
		  double c;
		}

##枚举类型
	enum Week{
	  Mon,
	  Tue,
	  Wed,
	  Thur,
	  Fri,
	  Sat
	  Sun
	}

##函数指针
* 函数入口地址：函数保存在text代码段中起始位置，函数名代表函数的入口地址
* 函数指针：函数指针变量保存函数的入口地址
		
		#include <stdio.h>
		int add(int a,int b);
		int sub(int a,int b);
		//int * fun(char *a,int b);
		int aloOperaotr(int a,int b,int (*ptr)(int a,int b));
		int main(){
			//int (*ptr)(int,int)=add;
		  //	int * (*pfun)(char *,int); 
			int result=aloOperaotr(12,14,add); 
			
			printf("result=%d\n",result);
			//ptr=sub;
			result=aloOperaotr(12,13,sub); 
			
			printf("result=%d\n",result);
		} 
		int add(int a,int b){
			return a+b;
		}
		int sub(int a,int b){
			return a-b;
		}
		int aloOperaotr(int a,int b,int (*ptr)(int a,int b)){
			return ptr(a,b);
		}


##typedef
* typedef 给存在的数据类型起别名
* typedef int INTEGER;


##怎么使用jni
###JNI头

	typedef const struct JNINativeInterface* JNIEnv;
	JNIEnv<=>struct JNINativeInterface*
	JNIEnv *env;
	env:JNIEnv *<=>struct JNINativeInterface * *
	(**env).FindClass();
	(*env)->FindClass();

###jni涉及概念
* 交叉编译：一个平台给另一个平台编译代码
  不同的操作系统windows mac os x linux/unix ，不同的处理器架构都算不同平台，x86,arm,mips

* 本地编译：一个平台自己编译代码给自已用
* 工具链：一套编译的工具，编译过程中顺序调用的一套工具
* 交叉编译工具链：
* 函数库:函数的集合，其中的代码已经编译成二进制机器指令
  提供库至少需要提供两个文件，.h头文件声明库中的函数，.so/.a库文件包含函数的具体实现
* 静态链接库 .a 静态库只用在静态链接过程中，将库的二进制机器代码拷贝一份
 文件比较大，升级难度高  但不依赖具体的库文件
* 动态链接库 .so  动态库用在动态链接过程中，记录用到哪个库的哪个函数。在程序运行之前，需要先加载动态库
  文件比较小，节约运行内存，升级方便 ，但增加库管理的难度
* 如果是系统的库，链接是包装好了，如果是自己的库的话，则需要链接
  编译->链接->运行

### jni开发相关工具
* NDK native development kit 本地开发工具集

###JNI开发流程
* 1.新建模块，native声明本地方法，调用本地方法
* 2.在module的build.gradle中defaultConfig内添加ndk,写法如下
	 ndk{
           moduleName "hello"
       }
* 3.在调用本地方法的类中加载动态库，指定库名加载

		   static{
		        System.loadLibrary("hello");
		    }
	这时候可能会出现如下的错误

		  Error:NDK integration is deprecated in the current plugin.
		<a href="http://tools.android.com/tech-docs/new-build-system/gradle-experimental">Consider trying the new experimental plugin</a><br><a href="useDeprecatedNdk">Set "android.useDeprecatedNdk=true" in gradle.properties to continue using the current NDK integration</a>
	出现这种情况，莫慌，只要在gradle.properties中加入android.useDeprecatedNdk=true就可以
* 4.模块中新建jni文件夹，默认在main目录下

* 5.新建c或c++源码文件，如新建hello.c

* 6.在hello.c中,按要求实现本地方法相应的函数，其中头文件#include "hello.h"可以不要

		#include "hello.h" //包含的头文件优先在当前目录下查找，如果没有找到，再到系统头文件目录查找
		#include <jni.h>//提供java和c的基本类型及引用类型对应，声明数据转换方法
		/**
		*本地方法相应的函数名:Java_包名_类名_本地方法名
		*参数1 JNIEnv *env jni环境，调用转换数据方法
		*参数2 jobject obj 调用本地方法类的对象
		*/
		jstring Java_com_iblogstreet_facerecognition_MainActivity_getStringFromC(JNIEnv *env,jobject obj){
		    char buf[]=" from c";
		    return (*env)->NewStringUTF(env,buf);
		}

* 7.gradle同步，make module
* 8.运行程序


##javah生成本地方法相应函数声明

在命令行中，将目录切换到src\main中
javah -jni -d ../jni 包名.类名 --可能会出现找不到类名
可以使用如下
javah -jni -classpath . -d ../jni com.china.face.units.JniUti
ls


##jni编程常见错误
* 库名找不到
   *1.加载库名不正确
   *2.没有生成相应平台的库
* 找不到方法
	*方法名不规范
	*实现的本地方法相应函数名写错
	*没有加载库


* INVALID HEAP ADDRESS IN dlfree addr=0xb7c1a748


* JNI DETECTED ERROR IN APPLICATION: can't call void com.iblogstreet.alipay.MainActivity.showDialog(java.lang.String) on instance of java.lang.Class<com.iblogstreet.alipay.pay.Payment>
解决方案：只要在将Payment中的方法移置到MainActivity中就可以解决，暂时没有找到更好的方案




##Java和C数组传递
ArrayOperator.java

	public class ArrayOperator {
	    private static final String TAG = "ArrayOperator";
	    public  static native void sortArray(int[] arr);
	    static{
	        System.loadLibrary("array");
	    }
	
	}

array.c

	#include <jni.h>
	#include <android/log.h>
	#include <stdio.h>
	
	#define LOG_TAG "JniAlipay"
	#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
	#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
	
	void sortArray(int *arr, int len) {
	    int i = 0;
	    int j = 0;
	    int tmp=0;
	    for (i = 0; i < len - 1; i++) {
	        for (j = 0; j < len - 1 - i; j++) {
	            if(arr[j]<arr[j+1]){
	                tmp=arr[j];
	                arr[j]=arr[j+1];
	                arr[j+1]=tmp;
	            }
	        }
	    }
	}
	
	void Java_com_iblogstreet_jnialipay_JniUnits_ArrayOperator_sortArray(JNIEnv *env, jobject obj, jintArray arr) {
	
	    //数组的长度
	    jsize len = (*env)->GetArrayLength(env, arr);
	    LOGD("len %d", len);
	    //jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
	    jint* arrs=(*env)->GetIntArrayElements(env,arr,NULL);
	
	
	    //对数组进行排序
	    sortArray(arrs, len);
	
	    (*env)->ReleaseIntArrayElements(env,arr,arrs,0);
	    LOGD("len %d", len);
	
	}
	//jsize GetArrayLength(JNIEnv *env, jarray array);
	//  jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
	// void        (*ReleaseIntArrayElements)(JNIEnv*, jintArray,jint*, jint);

其中使用到了如下三个方法

	jsize GetArrayLength(JNIEnv *env, jarray array);
	jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
	void        (*ReleaseIntArrayElements)(JNIEnv*, jintArray,jint*, jint);

##使用别人提供的.so库和JNI.java类
* JNI.java类放在其中指定的包下
* .so库放在src/main/jniLibs/架构/libxxx.so
  src--|
		main--jni
			--jniLibs

##C调用java相关的函数



##JNI打印日志
1.引入头文件

	#include <android/log.h>
	#define LOG_TAG "HelloWorld"
	#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
	#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
	#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, ##args)
		
2.在ndk{}中
引入
ldLibs "log" //指定链接Log库，反映到Android.mk中LOCAL_LDLIBS := \ -llog \
		
##C调用java中的方法



##javap输出方法的签名
* 在字节码com的同层目录中
切换到claaes\debug目录中
javap -classpath .-s 包名及类型

##jni开发三种模式##
* android开发工程师，android 应用，jni,本地方法相应函数
* android开发工程师，android应用,jni,有提供好的.so库，还有相应的JNI类
* android开发工程师，还有c/c++工程师，将c/c++工程师实现功能提供的函数，包装调用


##智能家居
1.实时获得各个房间环境信息，温度值，湿度，光照强度，红外信息，pm2.5---通过各种传感器
2.在家里有个智能控制终端，查看各个房间的环境信息，对各个房间的各种条件进行设置--android平板
3.能根据实时的环境信息对家里的各种智能电器进行控制--android平板
4.通过互联网实时查看检查家里的各种条件，还可以进行控制--android系统中增加了web服务器

目前：出的基本上是智能单品，原因在于没有统一的协议











