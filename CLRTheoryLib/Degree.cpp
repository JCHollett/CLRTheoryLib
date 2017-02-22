#include "Stdafx.h"
using namespace Mathematics;
namespace Mathematics {
    namespace Circular {
        Degree::Degree( double d ) : degs( d ) {}

        Degree::operator double( Degree^ d ) {
            return d->Value;
        }

        Degree::operator Degree( double d ) {
            return Degree( d );
        }
        Degree::operator Degree( Radian r ) {
            return Degree( r.Value * Constants::DegRads );
        }

        String ^ Degree::ToString() {
            return String::Format( "T = {0} Degrees" , this->degs );
        }
    }
}