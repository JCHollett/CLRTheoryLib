#pragma once
using namespace System;
namespace Mathematics {
    public ref class Constants {
        public:
        const static double PI = 3.141592653589793238462643383279502;
        const static double DegRads = (180.0 / PI);
        const static double RadDegs = 1.0 / (DegRads);
    };
}