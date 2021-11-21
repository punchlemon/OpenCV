#include <opencv2/opencv.hpp>
//#pragma comment(lib, "opencv_world400.lib")

using namespace cv;
using namespace std;

static void cvt(InputArray inputSrc_) {
  int type = inputSrc_.kind() & _InputArray::KIND_MASK;

  cout << inputSrc_.kind() << endl;
  cout << _InputArray::KIND_MASK << endl;

  if(inputSrc_.isMat()) {
    Mat src = inputSrc_.getMat();
    Mat dst;
    flip(src, dst, 1);

    imshow("src", src);
    imshow("dst", dst);
  } else if (inputSrc_.isUMat()) {
    UMat usrc = inputSrc_.getUMat();
    UMat udst;
    cvtColor(usrc, udst, COLOR_RGB2GRAY);

    imshow("usrc", usrc);
    imshow("udst", udst);
  }
}

int main(int argc, char* argv[]) {
  Mat src;
  UMat usrc;

  if(argc < 2) {
    cerr << "no parameter" << endl;
    return -1;
  }

  src = imread(argv[1]);
  cvt(src);

  waitKey(0);
  destroyAllWindows();

  src.copyTo(usrc);

  cvt(usrc);

  waitKey(0);

  return 0;
}