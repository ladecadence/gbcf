
import java.io.File;
import javax.swing.*;
import javax.swing.filechooser.*;

public class GBRomFilter extends FileFilter {
    public boolean accept(File f) {
    if (f.isDirectory()) {
	return true;
    }

    String s = f.getName();
    int i = s.lastIndexOf('.');

    if (i > 0 &&  i < s.length() - 1) {
	String extension = s.substring(i+1).toLowerCase();
	if (extension.equals("gb") ||
	    extension.equals("gbc") ||
	    extension.equals("sgb") ) {
	        return true;
	} else {
	    return false;
	}
    }

    return false;
    }

    //The description of this filter
    public String getDescription() {
        return "GB Roms";
    }
}

