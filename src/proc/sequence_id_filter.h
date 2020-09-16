/* License: Apache 2.0. See LICENSE file in root directory.
Copyright(c) 2020 Intel Corporation. All Rights Reserved. */


#pragma once

#include "synthetic-stream.h"
#include "option.h"

namespace librealsense
{
    class sequence_id_filter : public generic_processing_block
    {
    public:
        sequence_id_filter();

    protected:
        bool should_process(const rs2::frame& frame) override;
        rs2::frame process_frame(const rs2::frame_source& source, const rs2::frame& f) override;

    private:
        bool is_selected_id(int stream_index);

        float _selected_stream_id;
        rs2::frame _last_frame[3];
    };
    MAP_EXTENSION(RS2_EXTENSION_SEQUENCE_ID_FILTER, librealsense::sequence_id_filter);
}