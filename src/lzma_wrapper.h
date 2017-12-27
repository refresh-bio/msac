#pragma once
// *******************************************************************************************
// This file is a part of MSAC software distributed under GNU GPL 3 licence.
// The homepage of the MSAC project is http://sun.aei.polsl.pl/msac
//
// Author: Sebastian Deorowicz
// Version: 1.0
// Date   : 2017-12-27
// *******************************************************************************************

#include <vector>
#include <string>

#define LZMA_API_STATIC
#include "lzma.h"

using namespace std;

// *******************************************************************************************
//
// *******************************************************************************************
class CLZMAWrapper 
{
	vector<uint8_t> *v_text;
	vector<uint8_t> *v_text_compressed;
	vector<uint8_t> *v_text_uncompressed;

	bool forward_mode;
	int compression_mode;

	void forward();
	void reverse();

	bool init_encoder(lzma_stream *strm, uint32_t preset);
	bool init_decoder(lzma_stream *strm);

	bool compress(lzma_stream *strm, vector<uint8_t> &v_in, vector<uint8_t> &v_out);
	bool decompress(lzma_stream *strm, vector<uint8_t> &v_in, vector<uint8_t> &v_out);

public:
	CLZMAWrapper(vector<uint8_t> *_v_text, vector<uint8_t> *_v_text_compressed, bool _forward_mode, int _compression_mode = 0) : 
		v_text(_v_text), v_text_compressed(_v_text_compressed), forward_mode(_forward_mode), compression_mode(_compression_mode)
	{
	};

	void operator()();
};

// EOF
