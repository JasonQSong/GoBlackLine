// KC2B.cpp: 主项目文件。

#include "stdafx.h"

#include "ControlForm.h"

using namespace KC2B;
/*
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// 在创建任何控件之前启用 Windows XP 可视化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// 创建主窗口并运行它
	Application::Run(gcnew ControlForm());
	return 0;
}
*/

#include <vector>
using namespace std;
void cvQR(CvMat *inputA,CvMat *q,CvMat *r)
{
 
 
	CvSize inputSize=cvGetSize(inputA);
	int width=inputSize.width;
	int height=inputSize.height;
	cvSetIdentity(q);
	cvCopy(inputA,r);
	vector<CvMat **> matMem;
	CvMat *tempH=cvCreateMat(height,height,CV_32FC1);
	matMem.push_back(&tempH);
	CvMat *v=cvCreateMat(height,1,CV_32FC1);
	matMem.push_back(&v);
	CvMat *tempCol=cvCreateMat(height,1,CV_32FC1);
	matMem.push_back(&tempCol);
	CvMat *tempCol2=cvCreateMat(height,1,CV_32FC1);
	matMem.push_back(&tempCol2);
	CvMat *iMat=cvCreateMat(height,height,CV_32FC1);
	matMem.push_back(&iMat);
	CvMat *transV=cvCreateMat(1,height,CV_32FC1);
	matMem.push_back(&transV);
 
	for (int i=0; i<width; i++)
	{
		float b[] = {0};
		CvMat temp;
		cvGetCol(r,&temp,i);							//get the i col
		cvCopy(&temp,tempCol);							//copy the row,don't hurt the original column
		cvGetSubRect(tempCol,&temp,cvRect(0,0,1,i));	//get the header
		if (temp.rows == 0 || temp.cols == 0)
			memcpy(temp.data.fl,b,sizeof(float));
		else
			cvZero(&temp);									//make it zero
		float colNorm=cvNorm(tempCol);					//get the norm of the current column
		cvZero(tempCol2);								//zero the e vector
		float tempval=cvGet2D(r,i,i).val[0];
		cvSet2D(tempCol2,i,0,cvScalar(tempval>0?-1:1*colNorm,0,0));	//set the new value
		cvSub(tempCol,tempCol2,v);						//subtract the two vectors,get v
 
		float val2=cvNorm(v);
		if (val2==0)
		{
			continue;
		}
		val2*=val2;
		val2=1/val2;
		cvTranspose(v,transV);
		cvMatMul(v,transV,tempH);						//
		cvScale(tempH,tempH,2*val2);	
		cvSetIdentity(iMat);							//the identity matrix
		cvSub(iMat,tempH,iMat);
		cvCopy(iMat,tempH);								//get the H matrix
		cvTranspose(tempH,tempH);						//transpose
		cvMatMul(q,tempH,q);							//q=q.h
		cvGetCol(r,&temp,i);							//get the col again
		cvSet2D(&temp,i,0,cvScalar(colNorm,0,0));		//set the norm
		cvGetSubRect(r,&temp,cvRect(i,i+1,1,height-i-1));
		if (temp.rows == 0 || temp.cols == 0)
			memcpy(temp.data.fl,b,sizeof(float));
		else
			cvZero(&temp);									//zero the submatrix
	}
 
	for (int j=0; j<matMem.size(); j++)
	{
		cvReleaseMat(matMem[j]);
	}
 
}
 
[STAThreadAttribute]
int main(array<System::String ^> ^args){
float matData[]={1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7};	
float rData[16];	
float qData[16];	
CvMat aMat=cvMat(4,4,CV_32FC1,matData);	
CvMat rMat=cvMat(4,4,CV_32FC1,rData);	
CvMat qMat=cvMat(4,4,CV_32FC1,qData);	
cvQR(&aMat,&qMat,&rMat);	
float det=cvDet(&qMat);	return 0;
}