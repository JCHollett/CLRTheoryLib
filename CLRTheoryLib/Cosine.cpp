#include "Stdafx.h"
namespace Mathematics {
    namespace Circular {
        namespace Functions {
            Cosine::Cosine( double f ) : c( f ) {
                if ( fabs( f ) > 1.0f ) {
                    throw NEW System::ArgumentException( String::Format( "Value [{0}], must be less than equal to |1|" , f ) );
                } else {
                    this->c = f;
                }
            }
            Cosine::Cosine( LinearAlgebra::Vector ^ A , LinearAlgebra::Vector ^ B ) {
                if ( A->NSpace == B->NSpace ) {
                    this->Value = Functions::Cosine( (A*B) / ((double)A*(double)B) ).Value;
                } else {
                    throw NEW System::ArithmeticException( "Vector NSpace mismatch" );
                }
            }
            Cosine::operator Cosine ^ (double f) {
                return NEW Cosine( f );
            }

            Cosine::operator double( Cosine ^ c ) {
                return c->Value;
            }

            String ^ Cosine::ToString() {
                return String::Format( "Cos T = {0}" , this->c );
            }
        }
    }
}