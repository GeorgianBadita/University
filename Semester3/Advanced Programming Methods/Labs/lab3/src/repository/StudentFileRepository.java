package repository;

import domain.entities.Student;
import domain.validators.IllegalArgumentException;
import domain.validators.Validator;
import domain.validators.ValidatorException;

import java.io.*;
import java.util.Objects;
import java.util.function.Predicate;

public class StudentFileRepository extends AbstractRepository<Student, Integer> {

    private String file;
    private Predicate<Student> nullStudent = Objects::isNull;
    private Predicate<Integer> length4 = x -> x.equals(4);

    /**
     * Constructor for StudentFileRepository
     * @param v - validator Student validator
     * @param f - repository file
     */
    public StudentFileRepository(Validator<Student> v, String f) {
        super(v);
        this.file = f;
        try {
            readFromFile();
        } catch (ValidatorException | IllegalArgumentException e) {
            e.printStackTrace();
        }
    }

    /**
     * Function to read students from file
     * @throws ValidatorException - if the student is invalid
     * @throws IllegalArgumentException - if some parameter is null
     */
    private void readFromFile() throws ValidatorException, IllegalArgumentException {
        try(BufferedReader br = new BufferedReader(new FileReader(new File(file)))) {
            String line;
            while((line = br.readLine()) != null){
                String[] splitted = line.split("\\|");
                if(length4.test(splitted.length)){
                    Student st = new Student(Integer.parseInt(splitted[0]), splitted[1], Integer.parseInt(splitted[2]), splitted[3]);
                    super.save(st);
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
     * @param st - student to save
     * @return - null if the student is saved, the student otherwise
     * @throws ValidatorException - if the student is invalid
     * @throws IllegalArgumentException - if the student is null
     */
    @Override
    public Student save(Student st) throws ValidatorException, IllegalArgumentException {
        Student saved = super.save(st);

        if(nullStudent.test(saved)){
            saveToFile();
            return null;
        }
        return saved;
    }

    /**
     * Function for saving to file the list of students
     */
    private void saveToFile(){
        try(PrintWriter pw = new PrintWriter(new FileWriter(file))) {

            super.findAll().forEach(
                    s -> pw.print(s.getID() + "|" + s.getName() + "|" + s.getGroup() + "|" + s.getEmail() + "\n")
            );
            /*
            for (Student s:
                 super.findAll()) {
                pw.print(s.getID() + "|" + s.getName() + "|" + s.getGroup() + "|" + s.getEmail() + "\n");
            }*/
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Overiding update function for files
     * @param st - student to update
     * @return - null if the student was updated, the student otherwise
     * @throws ValidatorException - if the given student is invalid
     * @throws IllegalArgumentException - if some parameter is null
     */
    @Override
    public Student update(Student st) throws ValidatorException, IllegalArgumentException {
        Student aux = super.update(st);
        saveToFile();
        return aux;
    }


    /**
     * Overriding delete method for files
     * @param id - id of the student tu be deleted
     * id must be not null
     * @return - the deleted student if it was deleted, null otherwise
     * @throws IllegalArgumentException - if id is null
     */
    @Override
    public Student delete(Integer id) throws IllegalArgumentException {
        Student aux = super.delete(id);
        saveToFile();
        return aux;
    }
}