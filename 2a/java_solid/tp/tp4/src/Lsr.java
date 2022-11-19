public class Lsr implements ICommand{
    // Display file info
    static void perform(Filee f){
        System.out.println(f);
    }

    // List recursively all Elements in dir
    static void perform(Directoryy d){
        System.out.println("Directory " + d.filename + " content :");
        for(Element e : d.fileList){
            if(e instanceof Directoryy){
                perform((Directoryy) e);
            }
            else System.out.println(e);
        }
        System.out.println("-----------------------");
    }
}
