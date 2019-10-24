package task_pck;

import java.util.ArrayList;
import java.util.Collections;

public class BubbleSort extends AbstractSorter{


    @Override
    public ArrayList<Integer> sort(ArrayList<Integer> arr) {
        boolean ok;
        ok = false;
        do{
            ok = true;
            for(int i = 0; i<arr.size() - 1; i++){
                int a = arr.get(i);
                int b = arr.get(i + 1);
                if(a > b){
                    Collections.swap(arr, i, i + 1);
                    ok = false;
                }

            }
        }while(!ok);
        return arr;
    }
}
