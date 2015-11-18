#pragma once

namespace Core {
	class IBoardUpdateCallback {
	public:
		virtual void onBoardUpdate() = 0;
	};
}