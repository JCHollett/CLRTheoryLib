#include "Stdafx.h"
using namespace Mathematics;
namespace Mathematics {
    namespace Circular {
        Radian::Radian( double r ) : rads( r ) {}

        Radian::operator double( Radian^ r ) {
            return r->Value;
        }

        Radian::operator Radian( double r ) {
            return Radian( r );
        }
        Radian::operator Radian( Degree  d ) {
            return Radian( d.Value * Constants::RadDegs );
        }

        String ^ Radian::ToString() {
            return String::Format( "T = {0} Radians" , this->rads );
        }
    }
}