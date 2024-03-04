#pragma once

class RightTriangle
{
	public:
		RightTriangle();
		double GetlegW();
		double GetlegH();
		void SetlegW(double legW);
		void SetlegH(double legH);
		double GetHypotenuse();
	private:
		double legW;
		double legH;
};