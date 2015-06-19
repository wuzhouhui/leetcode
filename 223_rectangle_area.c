int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int	overup, overdown, overleft, overright;
	int	overarea;

	overup = D < H ? D : H;
	overdown = B > F ? B : F;
	overleft = A > E ? A : E;
	overright = C < G ? C : G;
	if (overup <= overdown || overleft >= overright)
		overarea = 0;
	else 
		overarea = (overup - overdown) * (overright - overleft);
	return((D - B) * (C - A) + (H - F) * (G - E) - overarea);
}

int main(void)
{

}
