import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Streams {
    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
        //a
        //eliminate numbers not multiple of 3 or 7
        List<Integer> rest = numbers.stream()
                .filter(x -> {
                    if (!(x % 7 == 0 || x % 3 == 0)) {
                        return false;
                    }
                    return true;
                })
                .collect(Collectors.toList());

        //b
        List<Integer> rest2 = rest.stream()
                .map(x -> x - 1)
                .collect(Collectors.toList());

        //c
        System.out.println(
                rest2.stream()
                        .reduce((x, y) -> (x + y) % 5).stream().collect(Collectors.toList())
        );


        List<Integer> nb = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

        System.out.println(nb.stream()
                .filter(x -> {
                    if (!(x % 4 == 0)) {
                        return false;
                    }
                    return true;
                })
                .map(x -> x + 1)
                .reduce((x, y) -> (x + y) % 2)
                .stream().collect(Collectors.toList()));



        List<Integer> num = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);


        num.stream()
                .filter(x->{
                        if(!(x%3==0 || x%2 == 0))
                            return false;
                        return true;
                })
                .map(x->"A" + (x+1) + "B")
                .reduce((x,y)->(x+y))
                .stream().collect(Collectors.toList())
        .stream().forEach(System.out::println);


    }



}
