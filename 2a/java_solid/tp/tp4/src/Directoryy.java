import java.util.ArrayList;
import java.util.List;

public class Directoryy extends Element{
    ArrayList<Element> fileList = new ArrayList<Element>();

    Directoryy(String filename, int rights){
        super(filename, rights);
    }

    Directoryy(String filename){
        super(filename);
        this.rights = 755;
    }


    //add an Element in dir
    void add(Element e) {
        if(alreadyIn(e)) return;
        this.fileList.add(e);
        setSize();
    }

    // Check if Element is already in dir
    boolean alreadyIn(Element e){
        for (Element element : this.fileList) {
            if (element.filename == e.filename) {
                System.out.println("Element " + e.filename + " already in directory");
                return true;
            }
        }
        return false;
    }

    // List dir Elements
    void listFiles(){
        for(Element e: this.fileList){
            System.out.println(e);
        }
    }

    // Set size of dir
    void setSize(){
        this.size = this.fileList.size() + 1;
    }

    // toString
    public String toString(){
        return "Directory " + this.filename + " created with rights " + this.rights + " on " + this.creationDate;
    }
}
