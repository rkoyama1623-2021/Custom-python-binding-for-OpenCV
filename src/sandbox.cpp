#include "sandbox.hpp"
namespace sandbox {
    void getImage( InputArray src, OutputArray dst ) {
        Mat s = src.getMat();
        Mat d = dst.getMat();
        d = s.clone();
        d.copyTo(dst);
    };
};
