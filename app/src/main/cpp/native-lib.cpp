#include <jni.h>
#include <string>
#include <random>
#include "../jni/com_wjx_android_ndksummary_MainActivity.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_wjx_android_ndksummary_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C" JNIEXPORT jstring Java_com_wjx_android_ndksummary_MainActivity_myStringFromJNI(JNIEnv *env, jobject){
    std::string hello = "My first jni from c++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jint Java_com_wjx_android_ndksummary_MainActivity_myAddFromJNI(JNIEnv *env, jobject jobject1){
    jclass clazz = (env)->GetObjectClass(jobject1);
    // 获取java中i字段的ID(最后一个参数是i的签名)
    jfieldID id_num1 = (env)->GetFieldID( clazz, "i", "I");
    // 获取num1字段对应的值
    jint num1 = (env)->GetIntField(jobject1 , id_num1);
    jfieldID id_num2 = (env)->GetFieldID(clazz, "j", "I");
    // 获取num2字段对应的值
    jint num2 = (
            env)->GetIntField(jobject1, id_num2);
    //拿到add方法的id，后面的为签名信息，括号内代表两个参数，都是I （int）返回也为I（int）的方法
    jmethodID methodId = (env)->GetMethodID(clazz, "add", "(II)I");
    // 调用它，拿到结果
    jint res = (env)->CallIntMethod(jobject1, methodId, num1, num2);
    return res;
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_wjx_android_ndksummary_MainActivity_myAddStringFrom(JNIEnv *env, jobject instance) {

    // TODO
    jclass clazz = (env)->GetObjectClass(instance);
    jfieldID s_a_id= (env)->GetFieldID(clazz, "a", "[Ljava/lang/String");
    jobject s_a = (env)->GetObjectField(instance, s_a_id);
    jfieldID s_b_id= (env)->GetFieldID(clazz, "b", "[Ljava/lang/String");
    jobject s_b = (env)->GetObjectField(instance, s_b_id);
    jfieldID s_c_id= (env)->GetFieldID(clazz, "c", "[Ljava/lang/String");
    jobject s_c = (env)->GetObjectField(instance, s_c_id);
    jmethodID jmethodID1 = (env)->GetMethodID(clazz, "addStr",
                                              "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");

    jstring result = static_cast<jstring>((env)->CallObjectMethod(instance, jmethodID1, s_a, s_b, s_c));
    return result;
}