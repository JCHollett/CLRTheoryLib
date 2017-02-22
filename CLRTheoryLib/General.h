#pragma once
#include "Stdafx.h"
using namespace System;
using namespace std;

namespace Mathematics {
	using namespace Circular;

	public ref class Function {
		private:
		static Functions::Cosine CosFunc( Radian p );
		static Functions::Sine SinFunc( Radian p );
		static Radian ACosFunc( Functions::Cosine t );
		static Radian ASinFunc( Functions::Sine t );
		public:
		static Func<Radian , Functions::Cosine>^ Cos = NEW Func<Radian , Functions::Cosine>( CosFunc );
		static Func<Radian , Functions::Sine>^ Sin = NEW Func<Radian , Functions::Sine>( SinFunc );
		static Func<Functions::Cosine , Radian>^ Acos = NEW Func<Functions::Cosine , Radian>( ACosFunc );
		static Func<Functions::Sine , Radian>^ Asin = NEW Func<Functions::Sine , Radian>( ASinFunc );
	};
}