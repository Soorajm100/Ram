package pendulum;

/**
 *
 * @author user
 */
import java.awt.*;                                      //its the API to develop GUI or window-based applications in java.
import javax.swing.*;                                  // includes all the tools for gui like jframe ,textfield etc to develop an interface
 
public class Pendulum extends JPanel implements Runnable {                 //defining thee pendulum class with inheritance jpanel is the panel or template in which the output comes
 
    private double angle = Math.PI / 2;
    private int length;
 
    public Pendulum(int length) {                                 //memeber function
        this.length = length;
        setDoubleBuffered(true);
    }
 
    @Override
    public void paint(Graphics guru) {              // creating an object    guru for graphics              
        guru.setColor(Color.WHITE);                                                 //sets the white background
                                                /*int getWidth()
                                                 --- return the width of the applet

                                               int get Height() 
                                                  --- return the height of the applet*/
        guru.fillRect(0, 0, getWidth(), getHeight());                             
        guru.setColor(Color.BLACK);                                 //sets the color of the pendulum  as black
        int anchorX = getWidth() / 2, anchorY = getHeight() / 4;
        int ballX = anchorX + (int) (Math.sin(angle) * length);
        int ballY = anchorY + (int) (Math.cos(angle) * length);
        guru.drawLine(anchorX, anchorY, ballX, ballY);              // used for the rope of the pendulum
        guru.fillOval(anchorX - 3, anchorY - 4, 7, 7);                 //fills the oval shaped pendulum or occupies that space. it covers half of oval
        guru.fillOval(ballX -7, ballY - 7, 14, 14);
    }
 
    public void run() {
        double angleAccel, angleVelocity = 0, dt = 0.1;
        while (true) {                                                                 //loop for finding the angle time to time
                                    
            angleAccel = -9.81 / length * Math.sin(angle);
            angleVelocity += angleAccel * dt;
            angle += angleVelocity * dt;
            repaint();
            try { Thread.sleep(15); } catch (InterruptedException ex) {}                  //to handle errors and to create a thread two cases included
                                                                                           //makes the thread to sleep for  milliseconds
        }
    }
 
    @Override
    public Dimension getPreferredSize() {
    
        return new Dimension(2 * length + 50, length / 2 * 3);              // functions of Java AWT and Swing return dimension object.                
    }
 
    public static void main(String[] args) {
        JFrame cool = new JFrame("Pendulum");                   //constructor  JFrame in which the f object is created
        Pendulum t = new Pendulum(200);                      // constructor Pendulum for which p object is created
        cool.add(t);
        cool.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);         
        cool.pack();                                                   // setting the contents inside the template
        cool.setVisible(true);                                          // to see the gui interface
        new Thread(t).start();                                           // a new thread is created and started
    }
} 
