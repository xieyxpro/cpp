四舍五入语句，保留几位小数就乘以10的几次方。  
float i = 12.3492;
i = (float)((int)(i*100.0+0.5))/100.0;

模拟六面骰子的投掷
 face = 1 + rand() % 6;
