package repository;

import domain.entities.Grade;
import domain.validators.IllegalArgumentException;
import domain.validators.Validator;
import domain.validators.ValidatorException;
import javafx.util.Pair;

import java.io.*;
import java.util.Objects;
import java.util.function.Predicate;

public class GradeFileRepository extends AbstractRepository<Grade,Pair<Integer,Integer>> {
    private String file;
    private Predicate<Grade> nullGrade = Objects::isNull;
    private Predicate<Integer> length5 = x -> x == 5;

    /**
     * Constructor for GradeFileRepository
     * @param v - validator Grade validator
     * @param f - repository file
     */
    public GradeFileRepository(Validator<Grade> v, String f) {
        super(v);
        this.file = f;
        try {
            readFromFile();
        } catch (ValidatorException | IllegalArgumentException e) {
            e.printStackTrace();
        }
    }

    /**
     * Function to read grades from file
     * @throws ValidatorException - if the grade is invalid
     * @throws IllegalArgumentException - if some parameter is null
     */
    private void readFromFile() throws ValidatorException, IllegalArgumentException {
        try(BufferedReader br = new BufferedReader(new FileReader(new File(file)))) {
            String line;
            while((line = br.readLine()) != null){
                String[] splitted = line.split("\\|");
                if(length5.test(splitted.length)){
                    Grade gr = new Grade(Integer.parseInt(splitted[0]), Integer.parseInt(splitted[1]),
                                         Double.parseDouble(splitted[2]), splitted[3], splitted[4]);
                    super.save(gr);
                }
                else {
                    System.out.println("The line is not good" + line);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Overriding save function for files
     * @param gr - grade to save
     * @return - null if the grade is saved, the grade otherwise
     * @throws ValidatorException - if the grade is invalid
     * @throws IllegalArgumentException - if the grade is null
     */
    @Override
    public Grade save(Grade gr) throws ValidatorException, IllegalArgumentException {
        Grade saved = super.save(gr);

        if(nullGrade.test(saved)){
            saveToFile();
            return null;
        }
        return saved;
    }

    /**
     * Function for saving to file the list of grades
     */
    private void saveToFile(){
        try(PrintWriter pw = new PrintWriter(new FileWriter(file))) {
            super.findAll().forEach(
                    gr -> {pw.print(gr.getStudId() + "|" + gr.getHwId() + "|" + gr.getGrade() + "|" +
                            gr.getProfName() +  "|" + gr.getFeedback() + "\n");}
            );

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Overiding update function for files
     * @param gr - grade to update
     * @return - null if the grade was updated, the grade otherwise
     * @throws ValidatorException - if the given grade is invalid
     * @throws IllegalArgumentException - if some parameter is null
     */
    @Override
    public Grade update(Grade gr) throws ValidatorException, IllegalArgumentException {
        Grade aux = super.update(gr);
        saveToFile();
        return aux;
    }


    /**
     * Overriding delete method for files
     * @param id - id of the grade to be deleted
     * id must be not null
     * @return - the deleted grade if it was deleted, null otherwise
     * @throws IllegalArgumentException - if id is null
     */
    @Override
    public Grade delete(Pair<Integer, Integer> id) throws IllegalArgumentException {
        Grade aux = super.delete(id);
        saveToFile();
        return aux;
    }
}
