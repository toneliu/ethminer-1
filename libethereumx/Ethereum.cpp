/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file Ethereum.cpp
 * @author Gav Wood <i@gavwood.com>
 * @date 2014
 */

#include "Ethereum.h"

#include <libethential/Log.h>
#include <libethereum/Client.h>
using namespace std;
using namespace eth;

Ethereum::Ethereum()
{
	ensureReady();
}

void Ethereum::ensureReady()
{
	while (!m_client && connectionOpen())
		try
		{
			m_client = unique_ptr<Client>(new Client("+ethereum+"));
			if (m_client)
				startServer();
		}
		catch (DatabaseAlreadyOpen)
		{
			startClient();
		}
}

Ethereum::~Ethereum()
{
}

bool Ethereum::connectionOpen() const
{
	return false;
}

void Ethereum::startClient()
{
}

void Ethereum::startServer()
{
}

void Client::flushTransactions()
{
}

std::vector<PeerInfo> Client::peers()
{
	return std::vector<PeerInfo>();
}

size_t Client::peerCount() const
{
	return 0;
}

void Client::connect(std::string const& _seedHost, unsigned short _port)
{
}

void Client::transact(Secret _secret, u256 _value, Address _dest, bytes const& _data, u256 _gas, u256 _gasPrice)
{
}

bytes Client::call(Secret _secret, u256 _value, Address _dest, bytes const& _data, u256 _gas, u256 _gasPrice)
{
	return bytes();
}

Address Client::transact(Secret _secret, u256 _endowment, bytes const& _init, u256 _gas, u256 _gasPrice)
{
	return Address();
}

void Client::inject(bytesConstRef _rlp)
{
}

u256 Client::balanceAt(Address _a, int _block) const
{
	return u256();
}

std::map<u256, u256> Client::storageAt(Address _a, int _block) const
{
	return std::map<u256, u256>();
}

u256 Client::countAt(Address _a, int _block) const
{
	return u256();
}

u256 Client::stateAt(Address _a, u256 _l, int _block) const
{
	return u256();
}

bytes Client::codeAt(Address _a, int _block) const
{
	return bytes();
}
