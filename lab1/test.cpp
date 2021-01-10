
int isAsciiDigit(int x) {
  
  int sign = 1<<31;

  int num1 = ~0x39+1;
  int num2 = ~0x30+1;

  num1 = num1+x;
  num2 = num2+x;

  num1 = num1&sign;
  num2 = num2&sign;

  return !(num1|(~num2));
}


int isAsciiDigit2(int x) {
  int sign = 0x1<<31;
  int upperBound = ~(sign|0x39);
  int lowerBound = ~0x30;
  upperBound = sign&(upperBound+x)>>31;
  lowerBound = sign&(lowerBound+1+x)>>31;
  return !(upperBound|lowerBound);
}

int main()
{

    int a = isAsciiDigit2(35);
    int b = isAsciiDigit(35);
    return 0;
}