package repository;

import domain.entities.Homework;
import domain.entities.Student;
import domain.validators.IllegalArgumentException;
import domain.validators.Validator;
import domain.validators.ValidatorException;

import java.io.*;
import java.util.Objects;
import java.util.function.Predicate;

public class HomeworkFileRepository extends AbstractRepository<Homework, Integer> {

    private String file;
    private Predicate<Homework> nullHw = Objects::isNull;
    private Predicate<Integer> length4 = x -> x.equals(4);

    /**
     * Constructor for HomeworkFileRepository
     * @param v - validator Homework validator
     * @param f - repository file
     */
    public HomeworkFileRepository(Validator<Homework> v, String f) {
        super(v);
        this.file = f;
        try {
            readFromFile();
        } catch (ValidatorException | IllegalArgumentException e) {
            e.printStackTrace();
        }
    }

    /**
     * Function to read homework from file
     * @throws ValidatorException - if the homework is invalid
     * @throws IllegalArgumentException - if some parameter is null
     */
    private void readFromFile() throws ValidatorException, IllegalArgumentException {
        try(BufferedReader br = new BufferedReader(new FileReader(new File(file)))) {
            String line;
            while((line = br.readLine()) != null){
                String[] splitted = line.split("\\|");
                if(length4.test(splitted.length)){
                    Homework hw = new Homework(Integer.parseInt(splitted[0]), splitted[1], Integer.parseInt(splitted[2]),
                            Integer.parseInt(splitted[3]));
                    super.save(hw);
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
     * @param hw - homework to save
     * @return - null if the homework is saved, the homework otherwise
     * @throws ValidatorException - if the homework is invalid
     * @throws IllegalArgumentException - if the homework is null
     */
    @Override
    public Homework save(Homework hw) throws ValidatorException, IllegalArgumentException {
        Homework saved = super.save(hw);

        if(nullHw.test(saved)){
            saveToFile();
            return null;
        }
        return saved;
    }

    /**
     * Function for saving to file the list of homework
     */
    private void saveToFile(){
        try(PrintWriter pw = new PrintWriter(new FileWriter(file))) {
            super.findAll().forEach(hw -> pw.print(
                    hw.getID() + "|" + hw.getDescription() + "|" + hw.getRecvWeek() + "|" + hw.getDeadlineWeek() +
                            "\n"
            ));
            /*for (Homework hw:
                    super.findAll()) {
                pw.print(hw.getID() + "|" + hw.getDescription() + "|" + hw.getRecvWeek() + "|" + hw.getDeadlineWeek() +
                        "\n");
            }*/
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Overiding update function for files
     * @param hw - homework to update
     * @return - null if the homework was updated, the homework otherwise
     * @throws ValidatorException - if the given Homework is invalid
     * @throws IllegalArgumentException - if some parameter is null
     */
    @Override
    public Homework update(Homework hw) throws ValidatorException, IllegalArgumentException {
        Homework aux = super.update(hw);
        saveToFile();
        return aux;
    }


    /**
     * Overriding delete method for files
     * @param id - id of the homework tu be deleted
     * id must be not null
     * @return - the deleted homework if it was deleted, null otherwise
     * @throws IllegalArgumentException - if id is null
     */
    @Override
    public Homework delete(Integer id) throws IllegalArgumentException {
        Homework aux = super.delete(id);
        saveToFile();
        return aux;
    }
}
