import java.util.*;

import aterm.*;
import aterm.pure.*;

public class TBAddressBookService implements AddressBookTif
{
  private static int id = 0;
  private static int createUniqueID() { return id++; }

  private static ATermFactory factory = new PureFactory();

  private Map addressById;
  private Map addressByName;

  public TBAddressBookService() {
    addressById = new HashMap();
    addressByName = new HashMap();
  }

  private IAddressBookEntry getEntry(int id) {
    return (IAddressBookEntry) addressById.get(new Integer(id));
  }

  public ATerm createEntry() {
    Integer id = new Integer(createUniqueID());
    IAddressBookEntry entry = new AddressBookEntry();
    addressById.put(id, entry);
    return factory.make("snd-value(new-entry(<int>))", id);
  }

  public void deleteEntry(int id) {
    addressById.remove(new Integer(id));
  }

  public void setName(int id, String name) {
    IAddressBookEntry entry = getEntry(id);
    addressByName.remove(name);
    addressByName.put(name, new Integer(id));
    entry.setName(name);
  }

  public void setAddress(int id, String address) {
    getEntry(id).setAddress(address);
  }

  public ATerm findByName(String name) {
    Integer id = (Integer) addressByName.get(name);
    if (id == null) {
      return factory.make("snd-value(not-found)");
    } else {
      return factory.make("snd-value(found(<int>))", id);
    }
  }

  public void recTerminate(ATerm t0) {}

  public static final void main(String[] args) throws Exception {
    TBAddressBookService service = new TBAddressBookService();
    AddressBookBridge bridge = new AddressBookBridge(factory, service);
    bridge.init(args);
    bridge.connect();
    bridge.run();
  }
}
