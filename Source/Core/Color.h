#pragma once

#define MIN_COL_VAL 0.0f
#define MAX_COL_VAL 255.f

struct Color
{
	Color(float R = 0, float G = 0, float B = 0, float A = MAX_COL_VAL)
	{
		SetR(R);
		SetG(G);
		SetB(B);
		SetA(A);
	}

private:
	float R;
	float G;
	float B;
	float A;
public:
	inline float GetR() { return R; }
	inline float GetG() { return G; }
	inline float GetB() { return B; }
	inline float GetA() { return A; }

	inline void SetR(float Val) { if(Val >= MIN_COL_VAL && Val <= MAX_COL_VAL) R = Val; }
	inline void SetG(float Val) { if(Val >= MIN_COL_VAL && Val <= MAX_COL_VAL) G = Val; }
	inline void SetB(float Val) { if(Val >= MIN_COL_VAL && Val <= MAX_COL_VAL) B = Val; }
	inline void SetA(float Val) { if(Val >= MIN_COL_VAL && Val <= MAX_COL_VAL) A = Val; }
};
