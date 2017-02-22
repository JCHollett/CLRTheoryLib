#pragma once
using namespace System;
namespace LinearAlgebra {
    public enum class Dimension {
        R1 = 1 , R2 , R3 , R4
    };

    public value struct Vector {
        private:
        double magnitude;
        static Converter<double , String^>^ DtoStr = NEW Converter<double , String^>( Convert::ToString );
        ARRAY( double ) ^ N;
        Dimension Dim;
        public:
        Vector( Dimension d );
        Vector( ... ARRAY( double ) ^ elements );
        property int NSpace {
            int get() {
                return (int)this->Dim;
            }
        }
        property double default[int]{
            double get( int index ) {
            return this->N[index];
        }
            void set( int index , double value ) {
                this->N[index] = value;
            }
        }
        static operator UnityEngine::Vector2( Vector v );
        static operator UnityEngine::Vector3( Vector v );
        static operator UnityEngine::Vector4( Vector v );
        static explicit operator double( Vector ^ A );
        static double operator*( Vector^ A , Vector^ B );
        static Vector^ operator*( Vector^ A , double B );
        static Vector^ operator*( double B , Vector^ A );
        static Vector^ operator+( Vector^ A , Vector^ B );
        static Vector^ operator-( Vector^ A , Vector^ B );
        virtual String^ ToString() override;
    };
};
