/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package org.geo.festival;

@SuppressWarnings({"cast", "rawtypes", "serial", "unchecked", "unused"})
@javax.annotation.Generated(value = "Autogenerated by Thrift Compiler (0.12.0)", date = "2019-05-07")
public class Concert implements org.apache.thrift.TBase<Concert, Concert._Fields>, java.io.Serializable, Cloneable, Comparable<Concert> {
  private static final org.apache.thrift.protocol.TStruct STRUCT_DESC = new org.apache.thrift.protocol.TStruct("Concert");

  private static final org.apache.thrift.protocol.TField ID_FIELD_DESC = new org.apache.thrift.protocol.TField("id", org.apache.thrift.protocol.TType.I32, (short)1);
  private static final org.apache.thrift.protocol.TField LOCATION_ID_FIELD_DESC = new org.apache.thrift.protocol.TField("locationId", org.apache.thrift.protocol.TType.I32, (short)2);
  private static final org.apache.thrift.protocol.TField ARTIST_ID_FIELD_DESC = new org.apache.thrift.protocol.TField("artistId", org.apache.thrift.protocol.TType.I32, (short)3);
  private static final org.apache.thrift.protocol.TField DATE_FIELD_DESC = new org.apache.thrift.protocol.TField("date", org.apache.thrift.protocol.TType.STRING, (short)4);
  private static final org.apache.thrift.protocol.TField TYPE_FIELD_DESC = new org.apache.thrift.protocol.TField("type", org.apache.thrift.protocol.TType.I32, (short)5);
  private static final org.apache.thrift.protocol.TField SEATS_SOLD_FIELD_DESC = new org.apache.thrift.protocol.TField("seatsSold", org.apache.thrift.protocol.TType.I32, (short)6);

  private static final org.apache.thrift.scheme.SchemeFactory STANDARD_SCHEME_FACTORY = new ConcertStandardSchemeFactory();
  private static final org.apache.thrift.scheme.SchemeFactory TUPLE_SCHEME_FACTORY = new ConcertTupleSchemeFactory();

  public int id; // required
  public int locationId; // required
  public int artistId; // required
  public @org.apache.thrift.annotation.Nullable java.lang.String date; // required
  /**
   * 
   * @see ConcertType
   */
  public @org.apache.thrift.annotation.Nullable ConcertType type; // required
  public int seatsSold; // required

  /** The set of fields this struct contains, along with convenience methods for finding and manipulating them. */
  public enum _Fields implements org.apache.thrift.TFieldIdEnum {
    ID((short)1, "id"),
    LOCATION_ID((short)2, "locationId"),
    ARTIST_ID((short)3, "artistId"),
    DATE((short)4, "date"),
    /**
     * 
     * @see ConcertType
     */
    TYPE((short)5, "type"),
    SEATS_SOLD((short)6, "seatsSold");

    private static final java.util.Map<java.lang.String, _Fields> byName = new java.util.HashMap<java.lang.String, _Fields>();

    static {
      for (_Fields field : java.util.EnumSet.allOf(_Fields.class)) {
        byName.put(field.getFieldName(), field);
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, or null if its not found.
     */
    @org.apache.thrift.annotation.Nullable
    public static _Fields findByThriftId(int fieldId) {
      switch(fieldId) {
        case 1: // ID
          return ID;
        case 2: // LOCATION_ID
          return LOCATION_ID;
        case 3: // ARTIST_ID
          return ARTIST_ID;
        case 4: // DATE
          return DATE;
        case 5: // TYPE
          return TYPE;
        case 6: // SEATS_SOLD
          return SEATS_SOLD;
        default:
          return null;
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, throwing an exception
     * if it is not found.
     */
    public static _Fields findByThriftIdOrThrow(int fieldId) {
      _Fields fields = findByThriftId(fieldId);
      if (fields == null) throw new java.lang.IllegalArgumentException("Field " + fieldId + " doesn't exist!");
      return fields;
    }

    /**
     * Find the _Fields constant that matches name, or null if its not found.
     */
    @org.apache.thrift.annotation.Nullable
    public static _Fields findByName(java.lang.String name) {
      return byName.get(name);
    }

    private final short _thriftId;
    private final java.lang.String _fieldName;

    _Fields(short thriftId, java.lang.String fieldName) {
      _thriftId = thriftId;
      _fieldName = fieldName;
    }

    public short getThriftFieldId() {
      return _thriftId;
    }

    public java.lang.String getFieldName() {
      return _fieldName;
    }
  }

  // isset id assignments
  private static final int __ID_ISSET_ID = 0;
  private static final int __LOCATIONID_ISSET_ID = 1;
  private static final int __ARTISTID_ISSET_ID = 2;
  private static final int __SEATSSOLD_ISSET_ID = 3;
  private byte __isset_bitfield = 0;
  public static final java.util.Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> metaDataMap;
  static {
    java.util.Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> tmpMap = new java.util.EnumMap<_Fields, org.apache.thrift.meta_data.FieldMetaData>(_Fields.class);
    tmpMap.put(_Fields.ID, new org.apache.thrift.meta_data.FieldMetaData("id", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I32)));
    tmpMap.put(_Fields.LOCATION_ID, new org.apache.thrift.meta_data.FieldMetaData("locationId", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I32)));
    tmpMap.put(_Fields.ARTIST_ID, new org.apache.thrift.meta_data.FieldMetaData("artistId", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I32)));
    tmpMap.put(_Fields.DATE, new org.apache.thrift.meta_data.FieldMetaData("date", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.TYPE, new org.apache.thrift.meta_data.FieldMetaData("type", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.EnumMetaData(org.apache.thrift.protocol.TType.ENUM, ConcertType.class)));
    tmpMap.put(_Fields.SEATS_SOLD, new org.apache.thrift.meta_data.FieldMetaData("seatsSold", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I32)));
    metaDataMap = java.util.Collections.unmodifiableMap(tmpMap);
    org.apache.thrift.meta_data.FieldMetaData.addStructMetaDataMap(Concert.class, metaDataMap);
  }

  public Concert() {
  }

  public Concert(
    int id,
    int locationId,
    int artistId,
    java.lang.String date,
    ConcertType type,
    int seatsSold)
  {
    this();
    this.id = id;
    setIdIsSet(true);
    this.locationId = locationId;
    setLocationIdIsSet(true);
    this.artistId = artistId;
    setArtistIdIsSet(true);
    this.date = date;
    this.type = type;
    this.seatsSold = seatsSold;
    setSeatsSoldIsSet(true);
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public Concert(Concert other) {
    __isset_bitfield = other.__isset_bitfield;
    this.id = other.id;
    this.locationId = other.locationId;
    this.artistId = other.artistId;
    if (other.isSetDate()) {
      this.date = other.date;
    }
    if (other.isSetType()) {
      this.type = other.type;
    }
    this.seatsSold = other.seatsSold;
  }

  public Concert deepCopy() {
    return new Concert(this);
  }

  @Override
  public void clear() {
    setIdIsSet(false);
    this.id = 0;
    setLocationIdIsSet(false);
    this.locationId = 0;
    setArtistIdIsSet(false);
    this.artistId = 0;
    this.date = null;
    this.type = null;
    setSeatsSoldIsSet(false);
    this.seatsSold = 0;
  }

  public int getId() {
    return this.id;
  }

  public Concert setId(int id) {
    this.id = id;
    setIdIsSet(true);
    return this;
  }

  public void unsetId() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __ID_ISSET_ID);
  }

  /** Returns true if field id is set (has been assigned a value) and false otherwise */
  public boolean isSetId() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __ID_ISSET_ID);
  }

  public void setIdIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __ID_ISSET_ID, value);
  }

  public int getLocationId() {
    return this.locationId;
  }

  public Concert setLocationId(int locationId) {
    this.locationId = locationId;
    setLocationIdIsSet(true);
    return this;
  }

  public void unsetLocationId() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __LOCATIONID_ISSET_ID);
  }

  /** Returns true if field locationId is set (has been assigned a value) and false otherwise */
  public boolean isSetLocationId() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __LOCATIONID_ISSET_ID);
  }

  public void setLocationIdIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __LOCATIONID_ISSET_ID, value);
  }

  public int getArtistId() {
    return this.artistId;
  }

  public Concert setArtistId(int artistId) {
    this.artistId = artistId;
    setArtistIdIsSet(true);
    return this;
  }

  public void unsetArtistId() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __ARTISTID_ISSET_ID);
  }

  /** Returns true if field artistId is set (has been assigned a value) and false otherwise */
  public boolean isSetArtistId() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __ARTISTID_ISSET_ID);
  }

  public void setArtistIdIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __ARTISTID_ISSET_ID, value);
  }

  @org.apache.thrift.annotation.Nullable
  public java.lang.String getDate() {
    return this.date;
  }

  public Concert setDate(@org.apache.thrift.annotation.Nullable java.lang.String date) {
    this.date = date;
    return this;
  }

  public void unsetDate() {
    this.date = null;
  }

  /** Returns true if field date is set (has been assigned a value) and false otherwise */
  public boolean isSetDate() {
    return this.date != null;
  }

  public void setDateIsSet(boolean value) {
    if (!value) {
      this.date = null;
    }
  }

  /**
   * 
   * @see ConcertType
   */
  @org.apache.thrift.annotation.Nullable
  public ConcertType getType() {
    return this.type;
  }

  /**
   * 
   * @see ConcertType
   */
  public Concert setType(@org.apache.thrift.annotation.Nullable ConcertType type) {
    this.type = type;
    return this;
  }

  public void unsetType() {
    this.type = null;
  }

  /** Returns true if field type is set (has been assigned a value) and false otherwise */
  public boolean isSetType() {
    return this.type != null;
  }

  public void setTypeIsSet(boolean value) {
    if (!value) {
      this.type = null;
    }
  }

  public int getSeatsSold() {
    return this.seatsSold;
  }

  public Concert setSeatsSold(int seatsSold) {
    this.seatsSold = seatsSold;
    setSeatsSoldIsSet(true);
    return this;
  }

  public void unsetSeatsSold() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __SEATSSOLD_ISSET_ID);
  }

  /** Returns true if field seatsSold is set (has been assigned a value) and false otherwise */
  public boolean isSetSeatsSold() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __SEATSSOLD_ISSET_ID);
  }

  public void setSeatsSoldIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __SEATSSOLD_ISSET_ID, value);
  }

  public void setFieldValue(_Fields field, @org.apache.thrift.annotation.Nullable java.lang.Object value) {
    switch (field) {
    case ID:
      if (value == null) {
        unsetId();
      } else {
        setId((java.lang.Integer)value);
      }
      break;

    case LOCATION_ID:
      if (value == null) {
        unsetLocationId();
      } else {
        setLocationId((java.lang.Integer)value);
      }
      break;

    case ARTIST_ID:
      if (value == null) {
        unsetArtistId();
      } else {
        setArtistId((java.lang.Integer)value);
      }
      break;

    case DATE:
      if (value == null) {
        unsetDate();
      } else {
        setDate((java.lang.String)value);
      }
      break;

    case TYPE:
      if (value == null) {
        unsetType();
      } else {
        setType((ConcertType)value);
      }
      break;

    case SEATS_SOLD:
      if (value == null) {
        unsetSeatsSold();
      } else {
        setSeatsSold((java.lang.Integer)value);
      }
      break;

    }
  }

  @org.apache.thrift.annotation.Nullable
  public java.lang.Object getFieldValue(_Fields field) {
    switch (field) {
    case ID:
      return getId();

    case LOCATION_ID:
      return getLocationId();

    case ARTIST_ID:
      return getArtistId();

    case DATE:
      return getDate();

    case TYPE:
      return getType();

    case SEATS_SOLD:
      return getSeatsSold();

    }
    throw new java.lang.IllegalStateException();
  }

  /** Returns true if field corresponding to fieldID is set (has been assigned a value) and false otherwise */
  public boolean isSet(_Fields field) {
    if (field == null) {
      throw new java.lang.IllegalArgumentException();
    }

    switch (field) {
    case ID:
      return isSetId();
    case LOCATION_ID:
      return isSetLocationId();
    case ARTIST_ID:
      return isSetArtistId();
    case DATE:
      return isSetDate();
    case TYPE:
      return isSetType();
    case SEATS_SOLD:
      return isSetSeatsSold();
    }
    throw new java.lang.IllegalStateException();
  }

  @Override
  public boolean equals(java.lang.Object that) {
    if (that == null)
      return false;
    if (that instanceof Concert)
      return this.equals((Concert)that);
    return false;
  }

  public boolean equals(Concert that) {
    if (that == null)
      return false;
    if (this == that)
      return true;

    boolean this_present_id = true;
    boolean that_present_id = true;
    if (this_present_id || that_present_id) {
      if (!(this_present_id && that_present_id))
        return false;
      if (this.id != that.id)
        return false;
    }

    boolean this_present_locationId = true;
    boolean that_present_locationId = true;
    if (this_present_locationId || that_present_locationId) {
      if (!(this_present_locationId && that_present_locationId))
        return false;
      if (this.locationId != that.locationId)
        return false;
    }

    boolean this_present_artistId = true;
    boolean that_present_artistId = true;
    if (this_present_artistId || that_present_artistId) {
      if (!(this_present_artistId && that_present_artistId))
        return false;
      if (this.artistId != that.artistId)
        return false;
    }

    boolean this_present_date = true && this.isSetDate();
    boolean that_present_date = true && that.isSetDate();
    if (this_present_date || that_present_date) {
      if (!(this_present_date && that_present_date))
        return false;
      if (!this.date.equals(that.date))
        return false;
    }

    boolean this_present_type = true && this.isSetType();
    boolean that_present_type = true && that.isSetType();
    if (this_present_type || that_present_type) {
      if (!(this_present_type && that_present_type))
        return false;
      if (!this.type.equals(that.type))
        return false;
    }

    boolean this_present_seatsSold = true;
    boolean that_present_seatsSold = true;
    if (this_present_seatsSold || that_present_seatsSold) {
      if (!(this_present_seatsSold && that_present_seatsSold))
        return false;
      if (this.seatsSold != that.seatsSold)
        return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    int hashCode = 1;

    hashCode = hashCode * 8191 + id;

    hashCode = hashCode * 8191 + locationId;

    hashCode = hashCode * 8191 + artistId;

    hashCode = hashCode * 8191 + ((isSetDate()) ? 131071 : 524287);
    if (isSetDate())
      hashCode = hashCode * 8191 + date.hashCode();

    hashCode = hashCode * 8191 + ((isSetType()) ? 131071 : 524287);
    if (isSetType())
      hashCode = hashCode * 8191 + type.getValue();

    hashCode = hashCode * 8191 + seatsSold;

    return hashCode;
  }

  @Override
  public int compareTo(Concert other) {
    if (!getClass().equals(other.getClass())) {
      return getClass().getName().compareTo(other.getClass().getName());
    }

    int lastComparison = 0;

    lastComparison = java.lang.Boolean.valueOf(isSetId()).compareTo(other.isSetId());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetId()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.id, other.id);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetLocationId()).compareTo(other.isSetLocationId());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetLocationId()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.locationId, other.locationId);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetArtistId()).compareTo(other.isSetArtistId());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetArtistId()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.artistId, other.artistId);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetDate()).compareTo(other.isSetDate());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetDate()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.date, other.date);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetType()).compareTo(other.isSetType());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetType()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.type, other.type);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetSeatsSold()).compareTo(other.isSetSeatsSold());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetSeatsSold()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.seatsSold, other.seatsSold);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    return 0;
  }

  @org.apache.thrift.annotation.Nullable
  public _Fields fieldForId(int fieldId) {
    return _Fields.findByThriftId(fieldId);
  }

  public void read(org.apache.thrift.protocol.TProtocol iprot) throws org.apache.thrift.TException {
    scheme(iprot).read(iprot, this);
  }

  public void write(org.apache.thrift.protocol.TProtocol oprot) throws org.apache.thrift.TException {
    scheme(oprot).write(oprot, this);
  }

  @Override
  public java.lang.String toString() {
    java.lang.StringBuilder sb = new java.lang.StringBuilder("Concert(");
    boolean first = true;

    sb.append("id:");
    sb.append(this.id);
    first = false;
    if (!first) sb.append(", ");
    sb.append("locationId:");
    sb.append(this.locationId);
    first = false;
    if (!first) sb.append(", ");
    sb.append("artistId:");
    sb.append(this.artistId);
    first = false;
    if (!first) sb.append(", ");
    sb.append("date:");
    if (this.date == null) {
      sb.append("null");
    } else {
      sb.append(this.date);
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("type:");
    if (this.type == null) {
      sb.append("null");
    } else {
      sb.append(this.type);
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("seatsSold:");
    sb.append(this.seatsSold);
    first = false;
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws org.apache.thrift.TException {
    // check for required fields
    // check for sub-struct validity
  }

  private void writeObject(java.io.ObjectOutputStream out) throws java.io.IOException {
    try {
      write(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(out)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private void readObject(java.io.ObjectInputStream in) throws java.io.IOException, java.lang.ClassNotFoundException {
    try {
      // it doesn't seem like you should have to do this, but java serialization is wacky, and doesn't call the default constructor.
      __isset_bitfield = 0;
      read(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(in)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private static class ConcertStandardSchemeFactory implements org.apache.thrift.scheme.SchemeFactory {
    public ConcertStandardScheme getScheme() {
      return new ConcertStandardScheme();
    }
  }

  private static class ConcertStandardScheme extends org.apache.thrift.scheme.StandardScheme<Concert> {

    public void read(org.apache.thrift.protocol.TProtocol iprot, Concert struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TField schemeField;
      iprot.readStructBegin();
      while (true)
      {
        schemeField = iprot.readFieldBegin();
        if (schemeField.type == org.apache.thrift.protocol.TType.STOP) { 
          break;
        }
        switch (schemeField.id) {
          case 1: // ID
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.id = iprot.readI32();
              struct.setIdIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 2: // LOCATION_ID
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.locationId = iprot.readI32();
              struct.setLocationIdIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 3: // ARTIST_ID
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.artistId = iprot.readI32();
              struct.setArtistIdIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 4: // DATE
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.date = iprot.readString();
              struct.setDateIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 5: // TYPE
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.type = org.geo.festival.ConcertType.findByValue(iprot.readI32());
              struct.setTypeIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 6: // SEATS_SOLD
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.seatsSold = iprot.readI32();
              struct.setSeatsSoldIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          default:
            org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
        }
        iprot.readFieldEnd();
      }
      iprot.readStructEnd();

      // check for required fields of primitive type, which can't be checked in the validate method
      struct.validate();
    }

    public void write(org.apache.thrift.protocol.TProtocol oprot, Concert struct) throws org.apache.thrift.TException {
      struct.validate();

      oprot.writeStructBegin(STRUCT_DESC);
      oprot.writeFieldBegin(ID_FIELD_DESC);
      oprot.writeI32(struct.id);
      oprot.writeFieldEnd();
      oprot.writeFieldBegin(LOCATION_ID_FIELD_DESC);
      oprot.writeI32(struct.locationId);
      oprot.writeFieldEnd();
      oprot.writeFieldBegin(ARTIST_ID_FIELD_DESC);
      oprot.writeI32(struct.artistId);
      oprot.writeFieldEnd();
      if (struct.date != null) {
        oprot.writeFieldBegin(DATE_FIELD_DESC);
        oprot.writeString(struct.date);
        oprot.writeFieldEnd();
      }
      if (struct.type != null) {
        oprot.writeFieldBegin(TYPE_FIELD_DESC);
        oprot.writeI32(struct.type.getValue());
        oprot.writeFieldEnd();
      }
      oprot.writeFieldBegin(SEATS_SOLD_FIELD_DESC);
      oprot.writeI32(struct.seatsSold);
      oprot.writeFieldEnd();
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

  }

  private static class ConcertTupleSchemeFactory implements org.apache.thrift.scheme.SchemeFactory {
    public ConcertTupleScheme getScheme() {
      return new ConcertTupleScheme();
    }
  }

  private static class ConcertTupleScheme extends org.apache.thrift.scheme.TupleScheme<Concert> {

    @Override
    public void write(org.apache.thrift.protocol.TProtocol prot, Concert struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TTupleProtocol oprot = (org.apache.thrift.protocol.TTupleProtocol) prot;
      java.util.BitSet optionals = new java.util.BitSet();
      if (struct.isSetId()) {
        optionals.set(0);
      }
      if (struct.isSetLocationId()) {
        optionals.set(1);
      }
      if (struct.isSetArtistId()) {
        optionals.set(2);
      }
      if (struct.isSetDate()) {
        optionals.set(3);
      }
      if (struct.isSetType()) {
        optionals.set(4);
      }
      if (struct.isSetSeatsSold()) {
        optionals.set(5);
      }
      oprot.writeBitSet(optionals, 6);
      if (struct.isSetId()) {
        oprot.writeI32(struct.id);
      }
      if (struct.isSetLocationId()) {
        oprot.writeI32(struct.locationId);
      }
      if (struct.isSetArtistId()) {
        oprot.writeI32(struct.artistId);
      }
      if (struct.isSetDate()) {
        oprot.writeString(struct.date);
      }
      if (struct.isSetType()) {
        oprot.writeI32(struct.type.getValue());
      }
      if (struct.isSetSeatsSold()) {
        oprot.writeI32(struct.seatsSold);
      }
    }

    @Override
    public void read(org.apache.thrift.protocol.TProtocol prot, Concert struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TTupleProtocol iprot = (org.apache.thrift.protocol.TTupleProtocol) prot;
      java.util.BitSet incoming = iprot.readBitSet(6);
      if (incoming.get(0)) {
        struct.id = iprot.readI32();
        struct.setIdIsSet(true);
      }
      if (incoming.get(1)) {
        struct.locationId = iprot.readI32();
        struct.setLocationIdIsSet(true);
      }
      if (incoming.get(2)) {
        struct.artistId = iprot.readI32();
        struct.setArtistIdIsSet(true);
      }
      if (incoming.get(3)) {
        struct.date = iprot.readString();
        struct.setDateIsSet(true);
      }
      if (incoming.get(4)) {
        struct.type = org.geo.festival.ConcertType.findByValue(iprot.readI32());
        struct.setTypeIsSet(true);
      }
      if (incoming.get(5)) {
        struct.seatsSold = iprot.readI32();
        struct.setSeatsSoldIsSet(true);
      }
    }
  }

  private static <S extends org.apache.thrift.scheme.IScheme> S scheme(org.apache.thrift.protocol.TProtocol proto) {
    return (org.apache.thrift.scheme.StandardScheme.class.equals(proto.getScheme()) ? STANDARD_SCHEME_FACTORY : TUPLE_SCHEME_FACTORY).getScheme();
  }
}

