package casestudy;

import java.rmi.Remote;

public interface AddressBook extends Remote {
  public void setAddress(String name, String address);
  public String getAddress(String name);
}
