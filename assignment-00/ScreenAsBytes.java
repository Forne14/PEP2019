public class ScreenAsBytes {

    public static void setPixel(byte[] screen, int width, int x, int y) {
        int screenHeight = screen.length/(width/8);

       if(x<8){
           int bitToConvert = (8-x)-1;
           screen[(width/8)*y] =(byte)(screen[(width/8)*y]+ (byte)power(2,2,bitToConvert));
           System.out.println(screen[(width/8)*y]);


        }else if (x>=8){
           int bitToConvert = (8-((x-8)))-1;
           screen[((width/8)*y)+1] = (byte) (screen[((width/8)*y)+1]+(byte)power(2,2,bitToConvert));
           System.out.println(screen[(width/8)*y+1]);
       }
    }


    public static int power(int value, int base, int exponent){
        if (value==base && exponent==0)
            return 1;
        else if (value!=base && exponent==0)
        {
            return value/base;
        }
        else
        {
            return power(value=value*base,base,exponent-1);
        }

    }

    public static void drawHorizontalLine(byte[] screen, int width, int startX, int endX, int y) {
        for (int i=startX;i<=endX;i++){
            setPixel(screen,width,i,y);
        }
    }
    
    public static void drawVerticalLine(byte[] screen, int width, int x, int startY, int endY) {
        for (int i=startY;i<=endY;i++){
            setPixel(screen,width,x,i);
        }
    }


}
