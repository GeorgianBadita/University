import utils.Helper;

public class main {
    public static void main(String[] args) {
        String path1 = "C:\\Users\\georg\\Desktop\\An3_sem1\\PPD\\Lab1_java\\src\\files\\test1.txt";
        String path2 = "C:\\Users\\georg\\Desktop\\An3_sem1\\PPD\\Lab1_java\\src\\files\\test2.txt";
        String pathExcel = "C:\\Users\\georg\\Desktop\\An3_sem1\\PPD\\Lab1_java\\src\\excel\\excel.csv";
        Helper helper = new Helper();

        helper.addLineToExcel(pathExcel, "asdasd,1251:12341");
        //System.out.println(helper.compareFiles(path1, path2, "real"));
        //helper.createRandomFile(path1, 10, 20, 30);
    }
}
