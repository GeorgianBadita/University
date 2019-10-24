package task_pck;

import java.util.ArrayList;
import java.util.Collections;

public class QuickSort extends AbstractSorter {
    @Override
    public ArrayList<Integer> sort(ArrayList<Integer> arr) {
        arr = quick_sort(0, arr.size() - 1, arr);
        return arr;
    }

    private ArrayList<Integer> quick_sort(int left, int right, ArrayList<Integer> arr) {

        if(right <= left){
            return arr;
        }

        int mid = (left + right) / 2;
        int pivot = arr.get(mid);
        int i = left, j = right;

        while(i < j){
            while(arr.get(i).compareTo(pivot) < 0){
                i ++;
            }
            while(arr.get(j).compareTo(pivot) > 0){
                j --;
            }

            if(i < j){
                Collections.swap(arr, i, j);
            }
        }

        quick_sort(left, j - 1, arr);
        quick_sort(j + 1, right, arr);

        return arr;
    }
}
