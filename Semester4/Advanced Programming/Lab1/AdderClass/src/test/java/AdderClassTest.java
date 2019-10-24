import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.junit.Test;

import static org.junit.Assert.*;

public class AdderClassTest {
    Logger logger = LogManager.getLogger("MyLogger");

    @Test
    public void add() {
        logger.entry("Entry add!!");
        AdderClass adder1 = new AdderClass(5);
        AdderClass adder2 = new AdderClass(7);
        assertEquals(adder1.add(adder2).a, 12);
        logger.traceExit("Exit add!!");
    }

    @Test
    public void subtract() {
        AdderClass adder1 = new AdderClass(5);
        AdderClass adder2 = new AdderClass(7);
        assertEquals(adder1.subtract(adder2).a, -2);
    }
}