#include "Graphic.h"



Graphic::Graphic(HWND hWnd)
{
	frameBuffer = 0;
	backBuffter = 0;
	sprite = 0;
	this->hWnd = hWnd;
	init();
}


Graphic::~Graphic()
{
	Release();
}
Graphic* Graphic::instance = 0;
Graphic* Graphic::getInstance()
{
	if (instance == 0) 
		instance = new Graphic(WINDOW->getHandleWindow());
	
	return instance;
}
bool Graphic::isInitDirectX() {
	LPDIRECT3D9 d3d;
	if (NULL == (d3d = Direct3DCreate9(D3D_SDK_VERSION)))
		return false;
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = VIEWPORT_WIDTH;
	d3dpp.BackBufferHeight = VIEWPORT_HEIGHT;

	if (FAILED(d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddv)))
	{
		return false;
	}

	if (!d3ddv)
		return false;

	d3d->Release();

	return true;
}
bool Graphic::isInitSprite() {
	return !FAILED(D3DXCreateSprite(d3ddv, &sprite));
}
bool Graphic::isSetFrameBuffer() {
	HRESULT hr = d3ddv->CreateOffscreenPlainSurface(272,
		192,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&frameBuffer,
		0);
	return !FAILED(hr);
}

bool Graphic::isSetBackBuffer() {
	HRESULT hr = d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffter);
	return !FAILED(hr);
}

void Graphic::init() {
	if (!isInitDirectX() || !isInitSprite() || !isSetBackBuffer() || !isSetFrameBuffer()) {
		error();
	}
}

void Graphic::error() {
	MessageBox(hWnd, "Khoi tao loi", "Error", MB_ICONERROR);
	PostQuitMessage(0);
}
void Graphic::Release() {
	if (d3ddv) {
		d3ddv->Release();
		d3ddv = 0;
	}
	if (frameBuffer) {
		frameBuffer->Release();
		frameBuffer = 0;
	}
	if (backBuffter)
	{
		backBuffter->Release();
		backBuffter = 0;
	}
	if (sprite) {
		sprite->Release();
		sprite = 0;
	}
}


LPDIRECT3DDEVICE9 Graphic::GetDevice() {
	return d3ddv;
}
LPDIRECT3DSURFACE9 Graphic::GetBackBuffer() {
	return backBuffter;
}
LPD3DXSPRITE Graphic::GetSprite() {
	return sprite;
}

void Graphic::BeginGraphics() {
	HRESULT hr = d3ddv->BeginScene();
	HRESULT hr1 = sprite->Begin(D3DXSPRITE_ALPHABLEND);
	d3ddv->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(10, 10, 10), 1.0f, 0);
	if (FAILED(hr) || FAILED(hr1)) {
		MessageBox(hWnd, "Loi khi bat dau ve", "Error", MB_ICONERROR);
		PostQuitMessage(0);
	}
}

void Graphic::EndGraphics() {
	HRESULT hr = d3ddv->EndScene();
	HRESULT hr1 = sprite->End();
	if (FAILED(hr) || FAILED(hr1)) {
		MessageBox(hWnd, "Loi khi ket thuc", "Error", MB_ICONERROR);
		PostQuitMessage(0);
	}
}
void Graphic::PresentBackBuffer() {
	d3ddv->Present(0, 0, 0, 0);
}