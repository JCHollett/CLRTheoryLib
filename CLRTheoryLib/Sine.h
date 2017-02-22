#pragma once
using namespace System;
namespace Mathematics {
    namespace Circular {
        namespace Functions {
            public value struct Sine {
                private:
                double s;
                public:
                Sine( double f );
                Sine( LinearAlgebra::Vector ^ A , LinearAlgebra::Vector ^ B );

                property double Value {
                    double get() {
                        return this->s;
                    }
                private: void set( double s ) {
                    this->s = s;
                }
                }
                static operator Sine ^ (double f);
                static operator double( Sine ^ s );
                virtual String^ ToString() override;
            };
        }
    }
}