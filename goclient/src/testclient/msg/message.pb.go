// Code generated by protoc-gen-go.
// source: message.proto
// DO NOT EDIT!

/*
Package msg is a generated protocol buffer package.

It is generated from these files:
	message.proto

It has these top-level messages:
	CCSHead
	CMessageHead
	CMessage
	CMessageSet
*/
package msg

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
const _ = proto.ProtoPackageIsVersion1

// 消息实体
type EnMessageFE int32

const (
	EnMessageFE_FE_TIMER       EnMessageFE = 0
	EnMessageFE_FE_CLIENT      EnMessageFE = 1
	EnMessageFE_FE_GAMESERVER  EnMessageFE = 2
	EnMessageFE_FE_LOGINSERVER EnMessageFE = 3
	EnMessageFE_FE_DBSERVER    EnMessageFE = 4
	EnMessageFE_FE_PROXYSERVER EnMessageFE = 5
	EnMessageFE_FE_WORLDSERVER EnMessageFE = 6
	EnMessageFE_FE_WEBSERVER   EnMessageFE = 7
)

var EnMessageFE_name = map[int32]string{
	0: "FE_TIMER",
	1: "FE_CLIENT",
	2: "FE_GAMESERVER",
	3: "FE_LOGINSERVER",
	4: "FE_DBSERVER",
	5: "FE_PROXYSERVER",
	6: "FE_WORLDSERVER",
	7: "FE_WEBSERVER",
}
var EnMessageFE_value = map[string]int32{
	"FE_TIMER":       0,
	"FE_CLIENT":      1,
	"FE_GAMESERVER":  2,
	"FE_LOGINSERVER": 3,
	"FE_DBSERVER":    4,
	"FE_PROXYSERVER": 5,
	"FE_WORLDSERVER": 6,
	"FE_WEBSERVER":   7,
}

func (x EnMessageFE) Enum() *EnMessageFE {
	p := new(EnMessageFE)
	*p = x
	return p
}
func (x EnMessageFE) String() string {
	return proto.EnumName(EnMessageFE_name, int32(x))
}
func (x *EnMessageFE) UnmarshalJSON(data []byte) error {
	value, err := proto.UnmarshalJSONEnum(EnMessageFE_value, data, "EnMessageFE")
	if err != nil {
		return err
	}
	*x = EnMessageFE(value)
	return nil
}
func (EnMessageFE) EnumDescriptor() ([]byte, []int) { return fileDescriptor0, []int{0} }

// 客户端与服务器之间的消息头
type CCSHead struct {
	DialogID         *uint32 `protobuf:"varint,1,opt,name=DialogID,def=0" json:"DialogID,omitempty"`
	TeamID           *uint64 `protobuf:"varint,2,opt,name=TeamID" json:"TeamID,omitempty"`
	EntityID         *uint32 `protobuf:"varint,3,opt,name=EntityID" json:"EntityID,omitempty"`
	TimeStamp        *int64  `protobuf:"varint,4,opt,name=TimeStamp,def=0" json:"TimeStamp,omitempty"`
	XXX_unrecognized []byte  `json:"-"`
}

func (m *CCSHead) Reset()                    { *m = CCSHead{} }
func (m *CCSHead) String() string            { return proto.CompactTextString(m) }
func (*CCSHead) ProtoMessage()               {}
func (*CCSHead) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{0} }

const Default_CCSHead_DialogID uint32 = 0
const Default_CCSHead_TimeStamp int64 = 0

func (m *CCSHead) GetDialogID() uint32 {
	if m != nil && m.DialogID != nil {
		return *m.DialogID
	}
	return Default_CCSHead_DialogID
}

func (m *CCSHead) GetTeamID() uint64 {
	if m != nil && m.TeamID != nil {
		return *m.TeamID
	}
	return 0
}

func (m *CCSHead) GetEntityID() uint32 {
	if m != nil && m.EntityID != nil {
		return *m.EntityID
	}
	return 0
}

func (m *CCSHead) GetTimeStamp() int64 {
	if m != nil && m.TimeStamp != nil {
		return *m.TimeStamp
	}
	return Default_CCSHead_TimeStamp
}

// 消息头( server -> client 可以只填messageid, 但 client -> server 必须全填)
type CMessageHead struct {
	MessageID        *uint32 `protobuf:"varint,1,req,name=MessageID,def=0" json:"MessageID,omitempty"`
	XXX_unrecognized []byte  `json:"-"`
}

func (m *CMessageHead) Reset()                    { *m = CMessageHead{} }
func (m *CMessageHead) String() string            { return proto.CompactTextString(m) }
func (*CMessageHead) ProtoMessage()               {}
func (*CMessageHead) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{1} }

const Default_CMessageHead_MessageID uint32 = 0

func (m *CMessageHead) GetMessageID() uint32 {
	if m != nil && m.MessageID != nil {
		return *m.MessageID
	}
	return Default_CMessageHead_MessageID
}

// 单个消息
type CMessage struct {
	MsgHead          *CMessageHead `protobuf:"bytes,1,req,name=MsgHead" json:"MsgHead,omitempty"`
	MsgPara          *uint64       `protobuf:"fixed64,2,opt,name=MsgPara,def=0" json:"MsgPara,omitempty"`
	XXX_unrecognized []byte        `json:"-"`
}

func (m *CMessage) Reset()                    { *m = CMessage{} }
func (m *CMessage) String() string            { return proto.CompactTextString(m) }
func (*CMessage) ProtoMessage()               {}
func (*CMessage) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{2} }

const Default_CMessage_MsgPara uint64 = 0

func (m *CMessage) GetMsgHead() *CMessageHead {
	if m != nil {
		return m.MsgHead
	}
	return nil
}

func (m *CMessage) GetMsgPara() uint64 {
	if m != nil && m.MsgPara != nil {
		return *m.MsgPara
	}
	return Default_CMessage_MsgPara
}

// 消息集合(与客户端约定：服务器给客户端下发消息时需要放入消息集合，但客户端上行服务器不需要)
type CMessageSet struct {
	MsgParas         [][]byte `protobuf:"bytes,1,rep,name=MsgParas" json:"MsgParas,omitempty"`
	XXX_unrecognized []byte   `json:"-"`
}

func (m *CMessageSet) Reset()                    { *m = CMessageSet{} }
func (m *CMessageSet) String() string            { return proto.CompactTextString(m) }
func (*CMessageSet) ProtoMessage()               {}
func (*CMessageSet) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{3} }

func (m *CMessageSet) GetMsgParas() [][]byte {
	if m != nil {
		return m.MsgParas
	}
	return nil
}

func init() {
	proto.RegisterType((*CCSHead)(nil), "msg.CCSHead")
	proto.RegisterType((*CMessageHead)(nil), "msg.CMessageHead")
	proto.RegisterType((*CMessage)(nil), "msg.CMessage")
	proto.RegisterType((*CMessageSet)(nil), "msg.CMessageSet")
	proto.RegisterEnum("msg.EnMessageFE", EnMessageFE_name, EnMessageFE_value)
}

var fileDescriptor0 = []byte{
	// 294 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x09, 0x6e, 0x88, 0x02, 0xff, 0x54, 0x8e, 0x31, 0x4f, 0x83, 0x40,
	0x18, 0x86, 0x3d, 0xa8, 0x85, 0x7e, 0x40, 0xa5, 0xa7, 0x43, 0x37, 0x0d, 0x71, 0x68, 0x1c, 0x88,
	0x71, 0x74, 0x13, 0xb8, 0xb6, 0x24, 0x50, 0x1a, 0x20, 0x55, 0x27, 0x73, 0x89, 0x17, 0x42, 0x22,
	0xa5, 0x29, 0x2c, 0xfe, 0x17, 0x7f, 0xac, 0x1f, 0xe7, 0x31, 0x38, 0xbe, 0xcf, 0x3d, 0xf7, 0x7e,
	0x2f, 0x38, 0x8d, 0xe8, 0x3a, 0x5e, 0x09, 0xff, 0x74, 0x6e, 0xfb, 0x96, 0xea, 0x4d, 0x57, 0x79,
	0x07, 0x30, 0xc2, 0xb0, 0xd8, 0x0a, 0xfe, 0x49, 0xaf, 0xc1, 0x8c, 0x6a, 0xfe, 0xd5, 0x56, 0x71,
	0xb4, 0x24, 0x77, 0x64, 0xe5, 0x3c, 0x93, 0x47, 0x3a, 0x87, 0x69, 0x29, 0x78, 0x83, 0x48, 0x43,
	0x34, 0xa1, 0x2e, 0x98, 0xec, 0xd8, 0xd7, 0xfd, 0x37, 0x12, 0x7d, 0x90, 0xe8, 0x0d, 0xcc, 0xca,
	0xba, 0x11, 0x45, 0xcf, 0x9b, 0xd3, 0x72, 0x82, 0x48, 0xc7, 0x7f, 0xde, 0x3d, 0xd8, 0x61, 0xfa,
	0x77, 0x4e, 0x96, 0xa3, 0xa5, 0xa2, 0x6c, 0xd7, 0x64, 0xbb, 0x17, 0x80, 0x39, 0x5a, 0xd4, 0x03,
	0x23, 0xed, 0xaa, 0x41, 0x96, 0xef, 0xd6, 0xd3, 0xc2, 0xc7, 0x81, 0xfe, 0xbf, 0x16, 0x2a, 0x9d,
	0x3d, 0x3f, 0x73, 0x39, 0x67, 0x3a, 0x74, 0xdc, 0x82, 0x35, 0x3a, 0x85, 0xe8, 0x87, 0x81, 0x4a,
	0xe9, 0xb0, 0x47, 0x5f, 0xd9, 0x0f, 0x3f, 0x04, 0x2c, 0x71, 0x54, 0xca, 0x9a, 0x51, 0x1b, 0xcc,
	0x35, 0xfb, 0x28, 0xe3, 0x94, 0xe5, 0xee, 0x05, 0x75, 0x60, 0x86, 0x29, 0x4c, 0x62, 0xb6, 0x2b,
	0x5d, 0x42, 0x17, 0xe0, 0x60, 0xdc, 0xbc, 0xa4, 0xac, 0x60, 0xf9, 0x01, 0x0d, 0x0d, 0x8f, 0xce,
	0x11, 0x25, 0xd9, 0x26, 0xde, 0x29, 0xa6, 0xd3, 0x2b, 0xb0, 0x90, 0x45, 0x81, 0x02, 0x13, 0x25,
	0xed, 0xf3, 0xec, 0xed, 0x5d, 0xb1, 0x4b, 0xc5, 0x5e, 0xb3, 0x3c, 0x89, 0x14, 0x9b, 0xe2, 0x3c,
	0x7b, 0x60, 0x6c, 0xfc, 0x69, 0x04, 0xda, 0x96, 0xfc, 0x06, 0x00, 0x00, 0xff, 0xff, 0x17, 0x82,
	0xba, 0x41, 0x9a, 0x01, 0x00, 0x00,
}
