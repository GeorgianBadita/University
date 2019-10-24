package repository;

import domain.entities.Grade;
import domain.entities.Student;
import domain.validators.IllegalArgumentException;
import domain.validators.Validator;
import domain.validators.ValidatorException;
import javafx.util.Pair;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
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

public class GradeXMLRepository extends AbstractRepository<Grade,Pair<Integer,Integer>> {
    private String file;
    private DocumentBuilderFactory factory;

    /**
     * XML File Repository Grade Constructor
     * @param v - Grade Validator
     * @param fileName - path to the XML File
     */
    public GradeXMLRepository(Validator<Grade> v, String fileName){
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
     * Function to read Grades from XML File
     * @throws ValidatorException if the grade is't well formed
     * @throws IllegalArgumentException - if parameters are null
     */
    private void readFromXML() throws ValidatorException, IllegalArgumentException {
        try {
            DocumentBuilder db = this.factory.newDocumentBuilder();
            Document doc = db.parse(new File(this.file));
            Element el = (Element) doc.getDocumentElement();

            NodeList nodeList = el.getElementsByTagName("grade");

            for(int i = 0; i<nodeList.getLength(); i++){
                Integer idSt, idHw;
                double grade;
                String profName, feedBack;
                Element item = (Element) nodeList.item(i);

                idSt = Integer.parseInt(item.getAttribute("idSt"));

                NodeList nodeList1 = item.getElementsByTagName("idHw");
                idHw = Integer.parseInt(nodeList1.item(0).getChildNodes().item(0).getNodeValue());

                nodeList1 = item.getElementsByTagName("gradeValue");
                grade = Double.parseDouble(nodeList1.item(0).getChildNodes().item(0).getNodeValue());

                nodeList1 = item.getElementsByTagName("profName");

                profName = nodeList1.item(0).getChildNodes().item(0).getNodeValue();

                nodeList1 = item.getElementsByTagName("feedback");

                feedBack = nodeList1.item(0).getChildNodes().item(0).getNodeValue();

                Grade gr = new Grade(idSt,idHw, grade, profName, feedBack);
                super.save(gr);
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
            Element el = doc.createElement("grades");

            doc.appendChild(el);

            for (Grade gr:
                    super.findAll()) {
                el.appendChild(getGrade(doc, gr.getStudId(), gr.getHwId(), gr.getGrade(), gr.getProfName(), gr.getFeedback()));
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
    private static Node getGrade(Document doc, Integer idSt, Integer idHw, double grade, String profName, String feedback){
        Element newGrade = doc.createElement("grade");

        newGrade.setAttribute("idSt", idSt.toString());

        //create idHw element
        newGrade.appendChild(getGradeElements(doc, "idHw", idHw.toString()));

        //create grade element
        newGrade.appendChild(getGradeElements(doc, "gradeValue", String.valueOf(grade)));

        //create profName element
        newGrade.appendChild(getGradeElements(doc, "profName", profName));

        //create feedback element
        newGrade.appendChild(getGradeElements(doc, "feedback", feedback));

        return newGrade;
    }

    /**
     * Utility method to create text node
     * @param doc - document type
     * @param name - property name
     * @param value - property value
     * @return a new node
     */
    private static Node getGradeElements(Document doc, String name, String value){
        Element node = doc.createElement(name);
        node.appendChild(doc.createTextNode(value));
        return node;
    }

    /**
     * Overriding save function for XML files
     * @param gr - grade to save
     * @return - null if the grade is saved, the grade otherwise
     * @throws ValidatorException - if the grade is invalid
     * @throws IllegalArgumentException - if the grade is null
     */
    @Override
    public Grade save(Grade gr) throws ValidatorException, IllegalArgumentException {
        Grade saved = super.save(gr);

        if(saved == null){
            writeToXML();
            return null;
        }
        return saved;
    }

    /**
     * Overiding update function for XML files
     * @param gr - Grade to update
     * @return - null if the grade was updated, the grade otherwise
     * @throws ValidatorException - if the given student is invalid
     * @throws IllegalArgumentException - if some parameter is null
     */
    @Override
    public Grade update(Grade gr) throws ValidatorException, IllegalArgumentException {
        Grade aux = super.update(gr);
        writeToXML();
        return aux;
    }


    /**
     * Overriding delete method for XML files
     * @param id - id of the grade tu be deleted
     * id must be not null
     * @return - the deleted grade if it was deleted, null otherwise
     * @throws IllegalArgumentException - if id is null
     */
    @Override
    public Grade delete(Pair<Integer, Integer> id) throws IllegalArgumentException {
        Grade aux = super.delete(id);
        writeToXML();
        return aux;
    }
}
