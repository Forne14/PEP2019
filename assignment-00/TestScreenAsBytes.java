public class TestScreenAsBytes {

    public static void main(String[] args) {

        int exitCode = 0;
    
        {

            byte[] screen = new byte[6]; // a screen 16 pixels wide and 3 pixels tall, all set to 0 by default, i.e. black
            ScreenAsBytes.setPixel(screen, 16, 2, 1); // set the third pixel on row 0 to 1

            byte[] answer = new byte[] {           0, 0,
                                                0x20, 0,
                                                   0, 0 };

            boolean theSame = true;

            for (int i = 0; i < screen.length; ++i) {
                if (screen[i] != answer[i]) {
                    theSame = false;
                    exitCode = 1;
                    break;
                }
            }

            if (theSame) {
                System.out.println("Test 0 passed: setting a single pixel worked as expected");
            } else {
                System.out.println("Test 0 failed: setting a single pixel did not work as expected");
            } 

        }

        {

            byte[] screen = new byte[6]; // a screen 16 pixels wide and 3 pixels tall, all set to 0 by default, i.e. black
            ScreenAsBytes.drawHorizontalLine(screen, 16, 1, 14, 1); // draw a line from pixels 1 to 14 (inclusive) on row 1

            byte[] answer = new byte[] {        0,           0,
                                         (byte) 0x7F, (byte) 0xFE,
                                                0,           0 };

            boolean theSame = true;

            for (int i = 0; i < screen.length; ++i) {
                if (screen[i] != answer[i]) {
                    theSame = false;
                    exitCode = 1;
                    break;
                }
            }

            if (theSame) {
                System.out.println("Test 1 passed: drawing a horizontal line worked as expected");
            } else {
                System.out.println("Test 1 failed: drawing a horizontal line did not work as expected");
            } 

        }

        {

            byte[] screen = new byte[6]; // a screen 16 pixels wide and 3 pixels tall, all set to 0 by default, i.e. black
            ScreenAsBytes.drawVerticalLine(screen, 16, 3, 0, 1); // draw a vertical line from pixel (3,0) to pixel (3,1)

            byte[] answer = new byte[] { (byte) 0x10, 0,
                                         (byte) 0x10, 0,
                                                0,    0 };

            boolean theSame = true;

            for (int i = 0; i < screen.length; ++i) {
                if (screen[i] != answer[i]) {
                    theSame = false;
                    exitCode = 1;
                    break;
                }
            }

            if (theSame) {
                System.out.println("Test 2 passed: drawing a vertical line worked as expected");
            } else {
                System.out.println("Test 2 failed: drawing a vertical line did not work as expected");
            } 

        }
        
        System.exit(exitCode);
    }

}
