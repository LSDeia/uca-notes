public interface ICommand {
    // Interface for commands like "Lsr" and "Dump"
    static void perform(Filee f){};
    static void perform(Directoryy d){};
}
