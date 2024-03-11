#pragma once

class RightTriangle //����� ����������� ������������
{
	public:
		RightTriangle(); //�����������
		double GetlegW(); //�������� ������ � 1 ������
		double GetlegH(); //�������� ������ � 2 ������
		void SetlegW(double legW); //������������� �������� 1 �������
		void SetlegH(double legH); //������������� �������� 2 �������
		double GetHypotenuse(); //�������� ����������
	private:
		double legW;
		double legH;
};