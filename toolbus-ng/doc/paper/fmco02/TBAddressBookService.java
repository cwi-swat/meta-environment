import java.util.*;

import aterm.*;
import aterm.pure.*;

public class TBAddressBookService implements AddressBookTif
{
  private static int id = 0;
  private static int createUniqueID() { return id++; }

  private static ATermFactory factory = new PureFactory();

  private Map addressMap;

  public AddressBookService() {
    addressMap = new HashMap();
  }

  private AddressBookEntry getEntry(int id) {
    return (AddressBookEntry) addressMap.get(new Integer(id));
  }

  public void deleteAddress(int id) {
    addressMap.remove(new Integer(id));
  }

  public void setName(int id, String name) {
    getEntry(id).setName(name);
  }

  public void setAddress(int id, String address) {
    System.out.println("setAddress: id=" + id + ", address=" + address);
    getEntry(id).setAddress(address);
  }

  public void setZip(int id, String zip) {
    getEntry(id).setZip(zip);
  }

  public ATerm createAddress() {
    Integer id = new Integer(createUniqueID());
    AddressBookEntry entry = new AddressBookEntry();
    addressMap.put(id, entry);
    return factory.make("snd-value(new-address(<int>))", id);
  }

  public void recTerminate(ATerm t0) {}

  public static final void main(String[] args) throws Exception {
    AddressBookService service = new AddressBookService();
    AddressBookBridge bridge = new AddressBookBridge(factory, service);
    bridge.init(args);
    bridge.connect();
    bridge.run();
  }
}
