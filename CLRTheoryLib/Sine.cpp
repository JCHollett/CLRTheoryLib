#include "Stdafx.h"
namespace Mathematics {
    namespace Circular {
        namespace Functions {
            Sine::Sine( double f ) : s( f ) {
                if ( fabs( f ) > 1.0f ) {
                    throw NEW System::ArgumentException( String::Format( "Value [{0}], must be less than equal to |1|" , f ) );
                } else {
                    this->s = f;
                }
            }
            Sine::Sine( LinearAlgebra::Vector ^ A , LinearAlgebra::Vector ^ B ) {
                if ( A->NSpace == B->NSpace ) {
                    this->Value = System::Math::Sqrt( 1.0f - System::Math::Pow( Functions::Cosine( A , B ).Value , 2 ) );
                } else {
                    throw NEW System::ArithmeticException( "Vector NSpace mismatch" );
                }
            }
            Sine::operator Sine ^ (double f) {
                return NEW Sine( f );
            }
            Sine::operator double( Sine ^ s ) {
                return s->Value;
            }
            String ^ Sine::ToString() {
                return String::Format( "Sin T = {0}" , this->s );
            }
        }
    }
}