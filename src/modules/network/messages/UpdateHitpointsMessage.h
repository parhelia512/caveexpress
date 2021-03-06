#pragma once

#include "network/IProtocolMessage.h"

class UpdateHitpointsMessage: public IProtocolMessage {
private:
	uint16_t _points;

public:
	explicit UpdateHitpointsMessage (uint16_t points) :
			IProtocolMessage(protocol::PROTO_UPDATEHITPOINTS), _points(points)
	{
	}

	PROTOCOL_CLASS_FACTORY(UpdateHitpointsMessage);

	explicit UpdateHitpointsMessage (ByteStream& input) :
			IProtocolMessage(protocol::PROTO_UPDATEHITPOINTS)
	{
		_points = input.readShort();
	}

	void serialize (ByteStream& out) const override
	{
		out.addByte(_id);
		out.addShort(_points);
	}

	inline uint16_t getHitpoints () const
	{
		return _points;
	}
};
