//
//  ContentView.swift
//  MyBitmovinPlayer
//
//  Created by Ewan Chelley on 18/12/2024.
//

import SwiftUI
import Combine
import BitmovinPlayer


struct ContentView: View {
    
    var body: some View {
        VStack {
            VideoPlayerView(
                player: a()
            )
        }
        .padding()
    }
    
    func a() -> Player {
        let player = PlayerFactory.create()
        //let playerView = PlayerView(player: player, frame: .zero)
         
        let sourceConfig = SourceConfig(url: URL(filePath: "https://vod-hls-uk-live.akamaized.net/usp/auth/vod/piff_abr_full_hd/9c1b5c-m00255fg/vf_m00255fg_66642f31-0b19-481c-bafe-a1d8b4435733.ism/mobile_wifi_main_sd_abr_v2_hls_master.m3u8?__gda__=1734628758_2a51a0733a6624dd169748b69df2690a")!, type: .hls)
        player.load(sourceConfig: sourceConfig)
        
        return player
    }
}



#Preview {
    ContentView()
}
