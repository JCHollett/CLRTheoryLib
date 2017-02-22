#pragma once
using namespace LinearAlgebra;
using namespace System;
namespace Mathematics {
    namespace Circular {
        public value struct Degree {
            private:
            double degs;
            public:
            Degree( double d );

            property double Value {
                double get() {
                    return this->degs;
                }
            private: void set( double f ) {
                this->degs = f;
            }
            };
            static operator double( Degree^ d );
            static operator Degree( double d );
            static explicit operator Degree( Radian r );
            virtual String^ ToString() override;
        };
    }
}