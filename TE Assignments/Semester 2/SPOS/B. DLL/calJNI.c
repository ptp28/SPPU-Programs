#include <jni.h>
#include <math.h>
#include <stdio.h>
#include "calJNI.h"

JNIEXPORT jint JNICALL Java_calJNI_add(JNIEnv *env, jobject thisObj,jint n1,jint n2)
{
jint sum;
sum = n1+n2;
return sum;
}

JNIEXPORT jint JNICALL Java_calJNI_sub(JNIEnv *env, jobject thisObj,jint n1,jint n2)
{
jint diff;
diff = n1-n2;
return diff;
}

JNIEXPORT jint JNICALL Java_calJNI_mul(JNIEnv *env, jobject thisObj,jint n1,jint n2)
{
jint pro;
pro = n1*n2;
return pro;
}

JNIEXPORT jint JNICALL Java_calJNI_div(JNIEnv *env, jobject thisObj,jint n1,jint n2)
{
jint quo;
quo = n1/n2;
return quo;
}
