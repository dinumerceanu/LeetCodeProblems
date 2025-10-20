import java.util.HashMap;
import java.util.Map;

public class Final_value_2011 {
    public static int finalValueAfterOperations(String[] operations) {
        Map<String, Integer> ops = new HashMap<>();
        int x = 0;

        ops.put("X++", 1);
        ops.put("++X", 1);
        ops.put("X--", -1);
        ops.put("--X", -1);

        for (String op : operations) {
            x += ops.get(op);
        }

        return x;
    }
    
    public static void main(String[] args) {
        String[] operations = {"--X","X++","X++"};

        System.out.println(finalValueAfterOperations(operations));
    }
}