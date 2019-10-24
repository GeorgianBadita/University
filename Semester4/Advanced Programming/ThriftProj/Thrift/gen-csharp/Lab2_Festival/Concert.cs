/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Thrift;
using Thrift.Collections;
using System.Runtime.Serialization;
using Thrift.Protocol;
using Thrift.Transport;

namespace Lab2_Festival
{

  #if !SILVERLIGHT
  [Serializable]
  #endif
  public partial class Concert : TBase
  {
    private int _id;
    private int _locationId;
    private int _artistId;
    private string _date;
    private ConcertType _type;
    private int _seatsSold;

    public int Id
    {
      get
      {
        return _id;
      }
      set
      {
        __isset.id = true;
        this._id = value;
      }
    }

    public int LocationId
    {
      get
      {
        return _locationId;
      }
      set
      {
        __isset.locationId = true;
        this._locationId = value;
      }
    }

    public int ArtistId
    {
      get
      {
        return _artistId;
      }
      set
      {
        __isset.artistId = true;
        this._artistId = value;
      }
    }

    public string Date
    {
      get
      {
        return _date;
      }
      set
      {
        __isset.date = true;
        this._date = value;
      }
    }

    /// <summary>
    /// 
    /// <seealso cref="ConcertType"/>
    /// </summary>
    public ConcertType Type
    {
      get
      {
        return _type;
      }
      set
      {
        __isset.type = true;
        this._type = value;
      }
    }

    public int SeatsSold
    {
      get
      {
        return _seatsSold;
      }
      set
      {
        __isset.seatsSold = true;
        this._seatsSold = value;
      }
    }


    public Isset __isset;
    #if !SILVERLIGHT
    [Serializable]
    #endif
    public struct Isset {
      public bool id;
      public bool locationId;
      public bool artistId;
      public bool date;
      public bool type;
      public bool seatsSold;
    }

    public Concert() {
    }

    public void Read (TProtocol iprot)
    {
      iprot.IncrementRecursionDepth();
      try
      {
        TField field;
        iprot.ReadStructBegin();
        while (true)
        {
          field = iprot.ReadFieldBegin();
          if (field.Type == TType.Stop) { 
            break;
          }
          switch (field.ID)
          {
            case 1:
              if (field.Type == TType.I32) {
                Id = iprot.ReadI32();
              } else { 
                TProtocolUtil.Skip(iprot, field.Type);
              }
              break;
            case 2:
              if (field.Type == TType.I32) {
                LocationId = iprot.ReadI32();
              } else { 
                TProtocolUtil.Skip(iprot, field.Type);
              }
              break;
            case 3:
              if (field.Type == TType.I32) {
                ArtistId = iprot.ReadI32();
              } else { 
                TProtocolUtil.Skip(iprot, field.Type);
              }
              break;
            case 4:
              if (field.Type == TType.String) {
                Date = iprot.ReadString();
              } else { 
                TProtocolUtil.Skip(iprot, field.Type);
              }
              break;
            case 5:
              if (field.Type == TType.I32) {
                Type = (ConcertType)iprot.ReadI32();
              } else { 
                TProtocolUtil.Skip(iprot, field.Type);
              }
              break;
            case 6:
              if (field.Type == TType.I32) {
                SeatsSold = iprot.ReadI32();
              } else { 
                TProtocolUtil.Skip(iprot, field.Type);
              }
              break;
            default: 
              TProtocolUtil.Skip(iprot, field.Type);
              break;
          }
          iprot.ReadFieldEnd();
        }
        iprot.ReadStructEnd();
      }
      finally
      {
        iprot.DecrementRecursionDepth();
      }
    }

    public void Write(TProtocol oprot) {
      oprot.IncrementRecursionDepth();
      try
      {
        TStruct struc = new TStruct("Concert");
        oprot.WriteStructBegin(struc);
        TField field = new TField();
        if (__isset.id) {
          field.Name = "id";
          field.Type = TType.I32;
          field.ID = 1;
          oprot.WriteFieldBegin(field);
          oprot.WriteI32(Id);
          oprot.WriteFieldEnd();
        }
        if (__isset.locationId) {
          field.Name = "locationId";
          field.Type = TType.I32;
          field.ID = 2;
          oprot.WriteFieldBegin(field);
          oprot.WriteI32(LocationId);
          oprot.WriteFieldEnd();
        }
        if (__isset.artistId) {
          field.Name = "artistId";
          field.Type = TType.I32;
          field.ID = 3;
          oprot.WriteFieldBegin(field);
          oprot.WriteI32(ArtistId);
          oprot.WriteFieldEnd();
        }
        if (Date != null && __isset.date) {
          field.Name = "date";
          field.Type = TType.String;
          field.ID = 4;
          oprot.WriteFieldBegin(field);
          oprot.WriteString(Date);
          oprot.WriteFieldEnd();
        }
        if (__isset.type) {
          field.Name = "type";
          field.Type = TType.I32;
          field.ID = 5;
          oprot.WriteFieldBegin(field);
          oprot.WriteI32((int)Type);
          oprot.WriteFieldEnd();
        }
        if (__isset.seatsSold) {
          field.Name = "seatsSold";
          field.Type = TType.I32;
          field.ID = 6;
          oprot.WriteFieldBegin(field);
          oprot.WriteI32(SeatsSold);
          oprot.WriteFieldEnd();
        }
        oprot.WriteFieldStop();
        oprot.WriteStructEnd();
      }
      finally
      {
        oprot.DecrementRecursionDepth();
      }
    }

    public override string ToString() {
      StringBuilder __sb = new StringBuilder("Concert(");
      bool __first = true;
      if (__isset.id) {
        if(!__first) { __sb.Append(", "); }
        __first = false;
        __sb.Append("Id: ");
        __sb.Append(Id);
      }
      if (__isset.locationId) {
        if(!__first) { __sb.Append(", "); }
        __first = false;
        __sb.Append("LocationId: ");
        __sb.Append(LocationId);
      }
      if (__isset.artistId) {
        if(!__first) { __sb.Append(", "); }
        __first = false;
        __sb.Append("ArtistId: ");
        __sb.Append(ArtistId);
      }
      if (Date != null && __isset.date) {
        if(!__first) { __sb.Append(", "); }
        __first = false;
        __sb.Append("Date: ");
        __sb.Append(Date);
      }
      if (__isset.type) {
        if(!__first) { __sb.Append(", "); }
        __first = false;
        __sb.Append("Type: ");
        __sb.Append(Type);
      }
      if (__isset.seatsSold) {
        if(!__first) { __sb.Append(", "); }
        __first = false;
        __sb.Append("SeatsSold: ");
        __sb.Append(SeatsSold);
      }
      __sb.Append(")");
      return __sb.ToString();
    }

  }

}
