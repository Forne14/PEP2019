public class SingleCharacterEdit {

    public static String singleCharacterEditWillTurnAIntoB(String a, String b) {

        char[] charArrayA = a.toCharArray();
        char[] charArrayB = b.toCharArray();

        if (charArrayA.length == charArrayB.length) {
            int counter =0;
            String phrase=null;
            for (int i = 0; i < charArrayA.length; i++) {
                if (charArrayA[i] != charArrayB[i]) {
                    counter++;
                    phrase = "replace," + i + "," + String.valueOf(charArrayB[i]);
                }
            }
            if (counter >1){return null;}
            return phrase;

        }
        if(charArrayA.length+1 == charArrayB.length){
            for (int i = 0; i < charArrayA.length; i++) {
                if (charArrayA[i] != charArrayB[i]){
                    return "insert,"+i+","+ String.valueOf(charArrayB[i]);
                }
                else{
                    return "insert,"+charArrayA.length+","+String.valueOf(charArrayB[charArrayA.length]);
                }
            }
        }
        if(charArrayA.length-1==charArrayB.length){
            for (int i = 0; i < charArrayA.length; i++) {
                if (charArrayA[i] != charArrayB[i]) {
                    return "remove," + i;
                }
            }
        }


        return null;
    }

}
