public class TestSingleCharacterEdit {

    public static void main(String[] args) {
    
        int exitCode = 0;
        {
            String test1 = SingleCharacterEdit.singleCharacterEditWillTurnAIntoB("cat","cab");
            
            if (test1 == null) {
                System.out.println("Test 0 failed: cat was not turned into cab, returned null");
                exitCode = 1;
            } else if (test1.equals("replace,2,b")) {
                System.out.println("Test 0 passed: cat was turned into cab");
            } else {
                System.out.println("Test 0 failed: the wrong single character edit was returned for turning cat into cab: " + test1);
                exitCode = 1;
            }
        }
        
        {
            String test2 = SingleCharacterEdit.singleCharacterEditWillTurnAIntoB("pikachu","blastoise");
            
            if (test2 == null) {
                System.out.println("Test 1 passed: pikachu was not turned into blastoise");
            } else {
                System.out.println("Test 1 failed: a single character edit was returned for turning pikachu into blastoise: " + test2);
                exitCode = 1;
            }
        }
        
        
        {
            String test3 = SingleCharacterEdit.singleCharacterEditWillTurnAIntoB("hat","hate");
            
            if (test3 == null) {
                System.out.println("Test 2 failed: hat could not be turned into hate");
                exitCode = 1;
            } else if (test3.equals("insert,3,e")) {
                System.out.println("Test 2 passed: hat was turned into hate");
            } else {
                System.out.println("Test 2 failed: the wrong single character edit was returned for turning hat into hate: " + test3);
                exitCode = 1;
            }
        }
        
        {
            String test4 = SingleCharacterEdit.singleCharacterEditWillTurnAIntoB("ghastly","gastly");
            
            if (test4 == null) {
                System.out.println("Test 3 failed: ghastly could not be turned into gastly");
                exitCode = 1;
            } else if (test4.equals("remove,1")) {
                System.out.println("Test 3 passed: ghastly was turned into gastly");
            } else {
                System.out.println("Test 3 failed: the wrong single character edit was returned for turning ghastly into gastly: " + test4);
                exitCode = 1;
            }
        }
        
        System.exit(exitCode);
        
    }

}
