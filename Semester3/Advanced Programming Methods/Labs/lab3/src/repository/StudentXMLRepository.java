package repository;

import domain.entities.Student;
import domain.validators.IllegalArgumentException;
import domain.validators.Validator;
import domain.validators.ValidatorException;
import org.w3c.dom.*;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;
import java.io.IOException;

public class StudentXMLRepository extends AbstractRepository<Student, Integer>{
    private String file;
    private DocumentBuilderFactory factory;

    /**
     * XML File Repository Student Constructor
     * @param v - Student Validator
     * @param fileName - path to the XML File
     */
    public StudentXMLRepository(Validator<Student> v, String fileName){
        super(v);
        this.file = fileName;
        this.factory = DocumentBuilderFactory.newInstance();
        try {
            readFromXML();
        } catch (ValidatorException | IllegalArgumentException e) {
            e.printStackTrace();
        }
    }


    /**
     * Function to read Students from XML File
     * @throws ValidatorException if the student is't well formed
     * @throws IllegalArgumentException - if parameters are null
     */
    private void readFromXML() throws ValidatorException, IllegalArgumentException {
        try {
            DocumentBuilder db = this.factory.newDocumentBuilder();
            Document doc = db.parse(new File(this.file));
            Element el = (Element) doc.getDocumentElement();

            NodeList nodeList = el.getElementsByTagName("student");

            for(int i = 0; i<nodeList.getLength(); i++){
                Integer id, group;
                String name, email;
                Element item = (Element) nodeList.item(i);

                id = Integer.parseInt(item.getAttribute("id"));

                NodeList nodeList1 = item.getElementsByTagName("name");
                name = nodeList1.item(0).getChildNodes().item(0).getNodeValue();

                nodeList1 = item.getElementsByTagName("group");

                group = Integer.parseInt(nodeList1.item(0).getChildNodes().item(0).getNodeValue());

                nodeList1 = item.getElementsByTagName("email");

                email = nodeList1.item(0).getChildNodes().item(0).getNodeValue();

                Student st = new Student(id, name, group, email);
                super.save(st);
            }

        } catch (ParserConfigurationException | SAXException | IOException e) {
            e.printStackTrace();
        }

    }

    /**
     * Function to write in XML File
     */
    private void writeToXML(){
        try {
            DocumentBuilder db = this.factory.newDocumentBuilder();

            Document doc = db.newDocument();
            Element el = doc.createElement("students");

            doc.appendChild(el);

            for (Student st:
                 super.findAll()) {
                el.appendChild(getStudent(doc, st.getID(), st.getName(), st.getGroup(), st.getEmail()));
            }

            TransformerFactory tf = TransformerFactory.newInstance();
            DOMSource ds = new DOMSource(doc);
            StreamResult sRes = new StreamResult(new File(this.file));
            Transformer transformer = tf.newTransformer();
            transformer.transform(ds, sRes);

        } catch (ParserConfigurationException | TransformerException e) {
            e.printStackTrace();
        }
    }

    /**
     * Function to get a new node to add into XML file
     */
    private static Node getStudent(Document doc, Integer id, String name, Integer group, String email){
        Element student = doc.createElement("student");

        student.setAttribute("id", id.toString());

        //create name element
        student.appendChild(getStudentElements(doc, "name", name));

        //create group element
        student.appendChild(getStudentElements(doc, "group", group.toString()));

        //create email element
        student.appendChild(getStudentElements(doc, "email", email));

        return student;
    }

    /**
     * Utility method to create text node
     * @param doc - document type
     * @param name - property name
     * @param value - property value
     * @return a new node
     */
    private static Node getStudentElements(Document doc, String name, String value){
        Element node = doc.createElement(name);
        node.appendChild(doc.createTextNode(value));
        return node;
    }

    /**
     * Overriding save function for XML files
     * @param st - student to save
     * @return - null if the student is saved, the student otherwise
     * @throws ValidatorException - if the student is invalid
     * @throws IllegalArgumentException - if the student is null
     */
    @Override
    public Student save(Student st) throws ValidatorException, IllegalArgumentException {
        Student saved = super.save(st);

        if(saved == null){
            writeToXML();
            return null;
        }
        return saved;
    }

    /**
     * Overiding update function for XML files
     * @param st - student to update
     * @return - null if the student was updated, the student otherwise
     * @throws ValidatorException - if the given student is invalid
     * @throws IllegalArgumentException - if some parameter is null
     */
    @Override
    public Student update(Student st) throws ValidatorException, IllegalArgumentException {
        Student aux = super.update(st);
        writeToXML();
        return aux;
    }


    /**
     * Overriding delete method for XML files
     * @param id - id of the student tu be deleted
     * id must be not null
     * @return - the deleted student if it was deleted, null otherwise
     * @throws IllegalArgumentException - if id is null
     */
    @Override
    public Student delete(Integer id) throws IllegalArgumentException {
        Student aux = super.delete(id);
        writeToXML();
        return aux;
    }
}

